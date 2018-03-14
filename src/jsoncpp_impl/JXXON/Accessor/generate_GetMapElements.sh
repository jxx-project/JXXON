#!/bin/sh

function GetMapElements_HPP {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetMapElements_INCLUDED
#define JXXON_Accessor_GetMapElements_INCLUDED

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template<typename T, template<typename...> class Base>
static void populateMap(Json::MapBase<T, Base>& map, const ::Json::Value& value, const std::function<T(const ::Json::Value::const_iterator&)>& valueAsT)
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

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_GetMapElements_INCLUDED
EOF
}

GetMapElements_HPP > GetMapElements.hpp

function GetMapElements_shared_ptr_HPP {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetMapElements_shared_ptr_INCLUDED
#define JXXON_Accessor_GetMapElements_shared_ptr_INCLUDED

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template<typename T, template<typename...> class Base>
static void populateMap(Json::MapBase<T, Base>& map, const ::Json::Value& value, const std::function<typename T::element_type(const ::Json::Value::const_iterator&)>& valueAsT)
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

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_GetMapElements_shared_ptr_INCLUDED
EOF
}

GetMapElements_shared_ptr_HPP > GetMapElements_shared_ptr.hpp

function Header {
cat << EOF | sed "s/{{INCLUDE}}/$1/g"| sed "s/{{BASE}}/$2/g"
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/{{INCLUDE}}"
#include <{{BASE}}>

namespace JXXON {
namespace Accessor {

EOF
}

function GetMapElements_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g" | sed "s/{{AS_TYPE}}/$3/g" 
template<>
GetMapElements<{{ELEMENT_TYPE}}, std::{{BASE}}>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<{{ELEMENT_TYPE}}, std::{{BASE}}>::operator()(Json::MapBase<{{ELEMENT_TYPE}}, std::{{BASE}}>& map) const
{
	populateMap<{{ELEMENT_TYPE}}, std::{{BASE}}>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->{{AS_TYPE}}();});
}

template GetMapElements<{{ELEMENT_TYPE}}, std::{{BASE}}>::GetMapElements(const Json& json);
template void GetMapElements<{{ELEMENT_TYPE}}, std::{{BASE}}>::operator()(Json::MapBase<{{ELEMENT_TYPE}}, std::{{BASE}}>& map) const;
EOF
}

function GetMapElements_shared_ptr_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g" | sed "s/{{AS_TYPE}}/$3/g" 
template<>
GetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>::operator()(Json::MapBase<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>& map) const
{
	populateMap<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->{{AS_TYPE}}();});
}

template GetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>::operator()(Json::MapBase<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>& map) const;
EOF
}

function Footer {
cat << EOF

} // namespace Accessor
} // namespace JXXON
EOF
}


function GetMapElements_BASE_CPP {

	BASE=$1
	    
	FILENAME=GetMapElements_${BASE}_string.cpp
	Header GetMapElements.hpp ${BASE} > ${FILENAME}
	GetMapElements_CPP ${BASE} std::string asString >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_shared_ptr_string.cpp
	Header GetMapElements_shared_ptr.hpp ${BASE} > ${FILENAME}
	GetMapElements_shared_ptr_CPP ${BASE} std::string asString >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_int.cpp
	Header GetMapElements.hpp ${BASE} > ${FILENAME}
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
	Header GetMapElements_shared_ptr.hpp ${BASE} > ${FILENAME}
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
	Header GetMapElements.hpp ${BASE} > ${FILENAME}
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
	Header GetMapElements_shared_ptr.hpp ${BASE} > ${FILENAME}
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
	Header GetMapElements.hpp ${BASE} > ${FILENAME}
	GetMapElements_CPP ${BASE} float asFloat >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	GetMapElements_CPP ${BASE} double asDouble >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_shared_ptr_float.cpp
	Header GetMapElements_shared_ptr.hpp ${BASE} > ${FILENAME}
	GetMapElements_shared_ptr_CPP ${BASE} float asFloat >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	GetMapElements_shared_ptr_CPP ${BASE} double asDouble >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_bool.cpp
	Header GetMapElements.hpp ${BASE} > ${FILENAME}
	GetMapElements_CPP ${BASE} bool asBool >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_shared_ptr_bool.cpp
	Header GetMapElements_shared_ptr.hpp ${BASE} > ${FILENAME}
	GetMapElements_shared_ptr_CPP ${BASE} bool asBool >> ${FILENAME}
	Footer >> ${FILENAME}

}

GetMapElements_BASE_CPP map
GetMapElements_BASE_CPP unordered_map
