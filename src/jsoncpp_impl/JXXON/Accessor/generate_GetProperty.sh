#!/bin/bash

function GetProperty_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_GetProperty_INCLUDED
#define JXXON_Accessor_GetProperty_INCLUDED

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"

namespace JXXON { namespace Accessor { namespace {

template<typename T>
T getChild(const ::Json::Value& value, const std::string& name, const std::function<T(const ::Json::Value&)>& valueAsT)
{
	if (!value.isNull()) {
		try {
			auto child = value.get(name, ::Json::Value::null);
			if (!child.isNull()) {
				return T(valueAsT(child));
			}
		} catch (std::exception& e) {
			throw Error(e.what());
		}
	}
	return T();
}

}}} // namespace JXXON::Accessor::

#endif // JXXON_Accessor_GetProperty_INCLUDED
EOF
}

GetProperty_TCC > GetProperty.tcc

function GetProperty_shared_ptr_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_GetProperty_shared_ptr_INCLUDED
#define JXXON_Accessor_GetProperty_shared_ptr_INCLUDED

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"

namespace JXXON { namespace Accessor { namespace {

template<typename T>
T getChild(
	const ::Json::Value& value,
	const std::string& name,
	const std::function<typename T::element_type(const ::Json::Value&)>& valueAsT)
{
	if (!value.isNull()) {
		try {
			auto child = value.get(name, ::Json::Value::null);
			if (!child.isNull()) {
				return std::make_shared<typename T::element_type>(valueAsT(child));
			}
		} catch (std::exception& e) {
			throw Error(e.what());
		}
	}
	return nullptr;
}

}}} // namespace JXXON::Accessor::

#endif // JXXON_Accessor_GetProperty_shared_ptr_INCLUDED
EOF
}

GetProperty_shared_ptr_TCC > GetProperty_shared_ptr.tcc

function Header {
cat << EOF | sed "s/{{INCLUDE}}/$1/g"
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/{{INCLUDE}}"
#include <cstdint>

namespace JXXON { namespace Accessor {

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
	return getChild<{{ELEMENT_TYPE}}>(json.pimpl->value, name, [](const ::Json::Value& value) { return value.{{AS_TYPE}}(); });
}

template GetProperty<{{ELEMENT_TYPE}}>::GetProperty(const Json& json, const std::string& name);
template {{ELEMENT_TYPE}} GetProperty<{{ELEMENT_TYPE}}>::operator()() const;
EOF
}

function GetProperty_shared_ptr_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g" | sed "s/{{AS_TYPE}}/$2/g"
template<>
GetProperty<std::shared_ptr<{{ELEMENT_TYPE}}>>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::shared_ptr<{{ELEMENT_TYPE}}> GetProperty<std::shared_ptr<{{ELEMENT_TYPE}}>>::operator()() const
{
	return getChild<std::shared_ptr<{{ELEMENT_TYPE}}>>(json.pimpl->value, name, [](const ::Json::Value& value) { return value.{{AS_TYPE}}(); });
}

template GetProperty<std::shared_ptr<{{ELEMENT_TYPE}}>>::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<{{ELEMENT_TYPE}}> GetProperty<std::shared_ptr<{{ELEMENT_TYPE}}>>::operator()() const;
EOF
}

function Footer {
cat << EOF

}} // namespace JXXON::Accessor
EOF
}

FILENAME=GetProperty_string.cpp
Header GetProperty.tcc > ${FILENAME}
GetProperty_CPP std::string asString >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetProperty_shared_ptr_string.cpp
Header GetProperty_shared_ptr.tcc > ${FILENAME}
GetProperty_shared_ptr_CPP std::string asString >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetProperty_int.cpp
Header GetProperty.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_INT8_T + 0)
EOF
GetProperty_CPP std::int8_t asInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT16_T + 0)
EOF
GetProperty_CPP std::int16_t asInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT32_T + 0)
EOF
GetProperty_CPP std::int32_t asInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT64_T + 0)
EOF
GetProperty_CPP std::int64_t asInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INTMAX_T + 0) && \\
	!((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || \\
	  (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
EOF
GetProperty_CPP std::intmax_t asLargestInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetProperty_shared_ptr_int.cpp
Header GetProperty_shared_ptr.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_INT8_T + 0)
EOF
GetProperty_shared_ptr_CPP std::int8_t asInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT16_T + 0)
EOF
GetProperty_shared_ptr_CPP std::int16_t asInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT32_T + 0)
EOF
GetProperty_shared_ptr_CPP std::int32_t asInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT64_T + 0)
EOF
GetProperty_shared_ptr_CPP std::int64_t asInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INTMAX_T + 0) && \\
	!((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || \\
	  (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
EOF
GetProperty_shared_ptr_CPP std::intmax_t asLargestInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetProperty_unsigned_int.cpp
Header GetProperty.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_UINT8_T + 0)
EOF
GetProperty_CPP std::uint8_t asUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT16_T + 0)
EOF
GetProperty_CPP std::uint16_t asUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT32_T + 0)
EOF
GetProperty_CPP std::uint32_t asUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT64_T + 0)
EOF
GetProperty_CPP std::uint64_t asUInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINTMAX_T + 0) && \\
	!((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || \\
	  (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
EOF
GetProperty_CPP std::uintmax_t asLargestUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetProperty_shared_ptr_unsigned_int.cpp
Header GetProperty_shared_ptr.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_UINT8_T + 0)
EOF
GetProperty_shared_ptr_CPP std::uint8_t asUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT16_T + 0)
EOF
GetProperty_shared_ptr_CPP std::uint16_t asUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT32_T + 0)
EOF
GetProperty_shared_ptr_CPP std::uint32_t asUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT64_T + 0)
EOF
GetProperty_shared_ptr_CPP std::uint64_t asUInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINTMAX_T + 0) && \\
	!((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || \\
	  (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
EOF
GetProperty_shared_ptr_CPP std::uintmax_t asLargestUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetProperty_float.cpp
Header GetProperty.tcc > ${FILENAME}
GetProperty_CPP float asFloat >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
GetProperty_CPP double asDouble >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetProperty_shared_ptr_float.cpp
Header GetProperty_shared_ptr.tcc > ${FILENAME}
GetProperty_shared_ptr_CPP float asFloat >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
GetProperty_shared_ptr_CPP double asDouble >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetProperty_bool.cpp
Header GetProperty.tcc > ${FILENAME}
GetProperty_CPP bool asBool >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetProperty_shared_ptr_bool.cpp
Header GetProperty_shared_ptr.tcc > ${FILENAME}
GetProperty_shared_ptr_CPP bool asBool >> ${FILENAME}
Footer >> ${FILENAME}
