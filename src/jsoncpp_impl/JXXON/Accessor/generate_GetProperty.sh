#!/bin/sh

function GetProperty_HPP {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetProperty_INCLUDED
#define JXXON_Accessor_GetProperty_INCLUDED

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"

namespace JXXON {
namespace Accessor {

template<typename T>
static T getChild(const ::Json::Value& value, const std::string& name, const std::function<T(const ::Json::Value&)>& valueAsT)
{
	if (!value.isNull()) {
		try {
			auto child = value.get(name, ::Json::Value::null);
			if (!child.isNull()) {
				return T(valueAsT(child));
			}
		} catch(std::exception& e) {
			throw Error(e.what());
		}
	}
	return T();
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_GetProperty_INCLUDED
EOF
}

GetProperty_HPP > GetProperty.hpp

function GetProperty_shared_ptr_HPP {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetProperty_shared_ptr_INCLUDED
#define JXXON_Accessor_GetProperty_shared_ptr_INCLUDED

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"

namespace JXXON {
namespace Accessor {

template<typename T>
static T getChild(const ::Json::Value& value, const std::string& name, const std::function<typename T::element_type(const ::Json::Value&)>& valueAsT)
{
	if (!value.isNull()) {
		try {
			auto child = value.get(name, ::Json::Value::null);
			if (!child.isNull()) {
				return std::make_shared<typename T::element_type>(valueAsT(child));
			}
		} catch(std::exception& e) {
			throw Error(e.what());
		}
	}
	return nullptr;
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_GetProperty_shared_ptr_INCLUDED
EOF
}

GetProperty_shared_ptr_HPP > GetProperty_shared_ptr.hpp

function Header {
cat << EOF | sed "s/{{INCLUDE}}/$1/g"
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/{{INCLUDE}}"

namespace JXXON {
namespace Accessor {

EOF
}

function GetProperty_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g" | sed "s/{{AS_TYPE}}/$2/g" 
template<>
GetProperty<{{ELEMENT_TYPE}}>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
{{ELEMENT_TYPE}} GetProperty<{{ELEMENT_TYPE}}>::operator()() const
{
	return getChild<{{ELEMENT_TYPE}}>(json.pimpl->value, name, [](const ::Json::Value& value){return value.{{AS_TYPE}}();});
}

template GetProperty<{{ELEMENT_TYPE}}>::GetProperty(const Json& json, const std::string& name);
template {{ELEMENT_TYPE}} GetProperty<{{ELEMENT_TYPE}}>::operator()() const;
EOF
}

function GetProperty_shared_ptr_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g" | sed "s/{{AS_TYPE}}/$2/g" 
template<>
GetProperty< std::shared_ptr<{{ELEMENT_TYPE}}> >::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::shared_ptr<{{ELEMENT_TYPE}}> GetProperty< std::shared_ptr<{{ELEMENT_TYPE}}> >::operator()() const
{
	return getChild< std::shared_ptr<{{ELEMENT_TYPE}}> >(json.pimpl->value, name, [](const ::Json::Value& value){return value.{{AS_TYPE}}();});
}

template GetProperty< std::shared_ptr<{{ELEMENT_TYPE}}> >::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<{{ELEMENT_TYPE}}> GetProperty< std::shared_ptr<{{ELEMENT_TYPE}}> >::operator()() const;
EOF
}

function Footer {
cat << EOF

} // namespace Accessor
} // namespace JXXON
EOF
}

FILENAME=GetProperty_string.cpp
Header GetProperty.hpp > ${FILENAME}
GetProperty_CPP std::string asString >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetProperty_shared_ptr_string.cpp
Header GetProperty_shared_ptr.hpp > ${FILENAME}
GetProperty_shared_ptr_CPP std::string asString >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetProperty_int.cpp
Header GetProperty.hpp > ${FILENAME}
GetProperty_CPP int asInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
GetProperty_CPP std::int64_t asInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
GetProperty_CPP std::intmax_t asLargestInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetProperty_shared_ptr_int.cpp
Header GetProperty_shared_ptr.hpp > ${FILENAME}
GetProperty_shared_ptr_CPP int asInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
GetProperty_shared_ptr_CPP std::int64_t asInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
GetProperty_shared_ptr_CPP std::intmax_t asLargestInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetProperty_unsigned_int.cpp
Header GetProperty.hpp > ${FILENAME}
GetProperty_CPP 'unsigned int' asUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
GetProperty_CPP std::uint64_t asUInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
GetProperty_CPP std::uintmax_t asLargestUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetProperty_shared_ptr_unsigned_int.cpp
Header GetProperty_shared_ptr.hpp > ${FILENAME}
GetProperty_shared_ptr_CPP 'unsigned int' asUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
GetProperty_shared_ptr_CPP std::uint64_t asUInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
GetProperty_shared_ptr_CPP std::uintmax_t asLargestUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetProperty_float.cpp
Header GetProperty.hpp > ${FILENAME}
GetProperty_CPP float asFloat >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
GetProperty_CPP double asDouble >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetProperty_shared_ptr_float.cpp
Header GetProperty_shared_ptr.hpp > ${FILENAME}
GetProperty_shared_ptr_CPP float asFloat >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
GetProperty_shared_ptr_CPP double asDouble >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetProperty_bool.cpp
Header GetProperty.hpp > ${FILENAME}
GetProperty_CPP bool asBool >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetProperty_shared_ptr_bool.cpp
Header GetProperty_shared_ptr.hpp > ${FILENAME}
GetProperty_shared_ptr_CPP bool asBool >> ${FILENAME}
Footer >> ${FILENAME}
