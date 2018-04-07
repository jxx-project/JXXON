#!/bin/bash

function GetMapElements_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetMapElements_INCLUDED
#define JXXON_Accessor_GetMapElements_INCLUDED

namespace JXXON { namespace Accessor {
namespace {

template<typename T, template<typename...> class Base>
void populateMap(Base<std::string, T>& map, const ::Json::Value& value, const std::function<T(const ::Json::Value::const_iterator&)>& valueAsT)
{
	map.clear();
	if (!value.isNull()) {
		if (value.isObject()) {
			try {
				for (auto i = value.begin(); i != value.end(); ++i) {
					map.emplace(i.key().asString(), i->isNull() ?  T() : T(valueAsT(i)));
				}
			} catch (std::exception& e) {
				throw Error(e.what());
			}
		} else {
			throw Error("Not an object");
		}
	}
}

} // namespace
}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_GetMapElements_INCLUDED
EOF
}

GetMapElements_TCC > GetMapElements.tcc

function GetMapElements_shared_ptr_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetMapElements_shared_ptr_INCLUDED
#define JXXON_Accessor_GetMapElements_shared_ptr_INCLUDED

namespace JXXON { namespace Accessor {
namespace {

template<typename T, template<typename...> class Base>
void populateMap(Base<std::string, T>& map, const ::Json::Value& value, const std::function<typename T::element_type(const ::Json::Value::const_iterator&)>& valueAsT)
{
	map.clear();
	if (!value.isNull()) {
		if (value.isObject()) {
			try {
				for (auto i = value.begin(); i != value.end(); ++i) {
					map.emplace(i.key().asString(), i->isNull() ? T() : std::make_shared<typename T::element_type>(valueAsT(i)));
				}
			} catch (std::exception& e) {
				throw Error(e.what());
			}
		} else {
			throw Error("Not an object");
		}
	}
}

} // namespace
}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_GetMapElements_shared_ptr_INCLUDED
EOF
}

GetMapElements_shared_ptr_TCC > GetMapElements_shared_ptr.tcc

function Header {
cat << EOF | sed "s/{{INCLUDE}}/$1/g"| sed "s/{{BASE}}/$2/g"
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/{{INCLUDE}}"
#include <cstdint>
#include <Polymorphic/{{BASE}}.h>

namespace JXXON { namespace Accessor {

EOF
}

function GetMapElements_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g" | sed "s/{{AS_TYPE}}/$3/g"
template<>
GetMapElements<{{ELEMENT_TYPE}}, Polymorphic::{{BASE}}>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<{{ELEMENT_TYPE}}, Polymorphic::{{BASE}}>::operator()(Polymorphic::{{BASE}}<std::string, {{ELEMENT_TYPE}}>& map) const
{
	populateMap<{{ELEMENT_TYPE}}, Polymorphic::{{BASE}}>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->{{AS_TYPE}}();});
}

template GetMapElements<{{ELEMENT_TYPE}}, Polymorphic::{{BASE}}>::GetMapElements(const Json& json);
template void GetMapElements<{{ELEMENT_TYPE}}, Polymorphic::{{BASE}}>::operator()(Polymorphic::{{BASE}}<std::string, {{ELEMENT_TYPE}}>& map) const;
EOF
}

function GetMapElements_shared_ptr_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g" | sed "s/{{AS_TYPE}}/$3/g"
template<>
GetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>, Polymorphic::{{BASE}}>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>, Polymorphic::{{BASE}}>::operator()(Polymorphic::{{BASE}}<std::string, std::shared_ptr<{{ELEMENT_TYPE}}>>& map) const
{
	populateMap<std::shared_ptr<{{ELEMENT_TYPE}}>, Polymorphic::{{BASE}}>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->{{AS_TYPE}}();});
}

template GetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>, Polymorphic::{{BASE}}>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>, Polymorphic::{{BASE}}>::operator()(Polymorphic::{{BASE}}<std::string, std::shared_ptr<{{ELEMENT_TYPE}}>>& map) const;
EOF
}

function Footer {
cat << EOF

}} // namespace JXXON::Accessor
EOF
}


function GetMapElements_BASE_CPP {

	BASE=$1

	FILENAME=GetMapElements_${BASE}_string.cpp
	Header GetMapElements.tcc ${BASE} > ${FILENAME}
	GetMapElements_CPP ${BASE} std::string asString >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_shared_ptr_string.cpp
	Header GetMapElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	GetMapElements_shared_ptr_CPP ${BASE} std::string asString >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_int.cpp
	Header GetMapElements.tcc ${BASE} > ${FILENAME}
	GetMapElements_CPP ${BASE} int asInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
	GetMapElements_CPP ${BASE} std::int64_t asInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
	GetMapElements_CPP ${BASE} std::intmax_t asLargestInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_shared_ptr_int.cpp
	Header GetMapElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	GetMapElements_shared_ptr_CPP ${BASE} int asInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
	GetMapElements_shared_ptr_CPP ${BASE} std::int64_t asInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
	GetMapElements_shared_ptr_CPP ${BASE} std::intmax_t asLargestInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_unsigned_int.cpp
	Header GetMapElements.tcc ${BASE} > ${FILENAME}
	GetMapElements_CPP ${BASE} 'unsigned int' asUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
	GetMapElements_CPP ${BASE} std::uint64_t asUInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
	GetMapElements_CPP ${BASE} std::uintmax_t asLargestUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_shared_ptr_unsigned_int.cpp
	Header GetMapElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	GetMapElements_shared_ptr_CPP ${BASE} 'unsigned int' asUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
	GetMapElements_shared_ptr_CPP ${BASE} std::uint64_t asUInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
	GetMapElements_shared_ptr_CPP ${BASE} std::uintmax_t asLargestUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_float.cpp
	Header GetMapElements.tcc ${BASE} > ${FILENAME}
	GetMapElements_CPP ${BASE} float asFloat >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	GetMapElements_CPP ${BASE} double asDouble >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_shared_ptr_float.cpp
	Header GetMapElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	GetMapElements_shared_ptr_CPP ${BASE} float asFloat >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	GetMapElements_shared_ptr_CPP ${BASE} double asDouble >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_bool.cpp
	Header GetMapElements.tcc ${BASE} > ${FILENAME}
	GetMapElements_CPP ${BASE} bool asBool >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_shared_ptr_bool.cpp
	Header GetMapElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	GetMapElements_shared_ptr_CPP ${BASE} bool asBool >> ${FILENAME}
	Footer >> ${FILENAME}

}

GetMapElements_BASE_CPP Map
GetMapElements_BASE_CPP UnorderedMap
