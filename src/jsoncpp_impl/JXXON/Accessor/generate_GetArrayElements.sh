#!/bin/sh

function GetArrayElements_HPP {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetArrayElements_INCLUDED
#define JXXON_Accessor_GetArrayElements_INCLUDED

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template<class T, template<typename...> class Base>
static void populateArray(Json::ArrayBase<T, Base>& array, const ::Json::Value& value, const std::function<T(const ::Json::Value::const_iterator&)>& valueAsT)
{
	array.clear();
	if (!value.isNull()) {
		if (value.isArray()) {
			try {
				for (auto i = value.begin(); i != value.end(); ++i) {
					array.emplace_back(i->isNull() ?  T() : T(valueAsT(i)));
				}
			} catch (std::exception& e) {
				throw Error(e.what());
			}
		} else {
			throw Error("Not an array");
		}
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_GetArrayElements_INCLUDED
EOF
}

GetArrayElements_HPP > GetArrayElements.hpp

function GetArrayElements_shared_ptr_HPP {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED
#define JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template<class T, template<typename...> class Base>
static void populateArray(Json::ArrayBase<T, Base>& array, const ::Json::Value& value, const std::function<typename T::element_type(const ::Json::Value::const_iterator&)>& valueAsT)
{
	array.clear();
	if (!value.isNull()) {
		if (value.isArray()) {
			try {
				for (auto i = value.begin(); i != value.end(); ++i) {
					array.emplace_back(i->isNull() ? T() : std::make_shared<typename T::element_type>(valueAsT(i)));
				}
			} catch (std::exception& e) {
				throw Error(e.what());
			}
		} else {
			throw Error("Not an array");
		}
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED
EOF
}

GetArrayElements_shared_ptr_HPP > GetArrayElements_shared_ptr.hpp

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

function GetArrayElements_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g" | sed "s/{{AS_TYPE}}/$3/g" 
template<>
GetArrayElements<{{ELEMENT_TYPE}}, std::{{BASE}}>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<{{ELEMENT_TYPE}}, std::{{BASE}}>::operator()(Json::ArrayBase<{{ELEMENT_TYPE}}, std::{{BASE}}>& array) const
{
	populateArray<{{ELEMENT_TYPE}}, std::{{BASE}}>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->{{AS_TYPE}}();});
}

template GetArrayElements<{{ELEMENT_TYPE}}, std::{{BASE}}>::GetArrayElements(const Json& json);
template void GetArrayElements<{{ELEMENT_TYPE}}, std::{{BASE}}>::operator()(Json::ArrayBase<{{ELEMENT_TYPE}}, std::{{BASE}}>& array) const;
EOF
}

function GetArrayElements_shared_ptr_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g" | sed "s/{{AS_TYPE}}/$3/g" 
template<>
GetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>::operator()(Json::ArrayBase<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>& array) const
{
	populateArray<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->{{AS_TYPE}}();});
}

template GetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>::operator()(Json::ArrayBase<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>& array) const;
EOF
}

function Footer {
cat << EOF

} // namespace Accessor
} // namespace JXXON
EOF
}


function GetArrayElements_BASE_CPP {

	BASE=$1
	    
	FILENAME=GetArrayElements_${BASE}_string.cpp
	Header GetArrayElements.hpp ${BASE} > ${FILENAME}
	GetArrayElements_CPP ${BASE} std::string asString >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_shared_ptr_string.cpp
	Header GetArrayElements_shared_ptr.hpp ${BASE} > ${FILENAME}
	GetArrayElements_shared_ptr_CPP ${BASE} std::string asString >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_int.cpp
	Header GetArrayElements.hpp ${BASE} > ${FILENAME}
	GetArrayElements_CPP ${BASE} int asInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
	GetArrayElements_CPP ${BASE} std::int64_t asInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
	GetArrayElements_CPP ${BASE} std::intmax_t asLargestInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_shared_ptr_int.cpp
	Header GetArrayElements_shared_ptr.hpp ${BASE} > ${FILENAME}
	GetArrayElements_shared_ptr_CPP ${BASE} int asInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
	GetArrayElements_shared_ptr_CPP ${BASE} std::int64_t asInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
	GetArrayElements_shared_ptr_CPP ${BASE} std::intmax_t asLargestInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_unsigned_int.cpp
	Header GetArrayElements.hpp ${BASE} > ${FILENAME}
	GetArrayElements_CPP ${BASE} 'unsigned int' asUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
	GetArrayElements_CPP ${BASE} std::uint64_t asUInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
	GetArrayElements_CPP ${BASE} std::uintmax_t asLargestUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_shared_ptr_unsigned_int.cpp
	Header GetArrayElements_shared_ptr.hpp ${BASE} > ${FILENAME}
	GetArrayElements_shared_ptr_CPP ${BASE} 'unsigned int' asUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
	GetArrayElements_shared_ptr_CPP ${BASE} std::uint64_t asUInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
	GetArrayElements_shared_ptr_CPP ${BASE} std::uintmax_t asLargestUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_float.cpp
	Header GetArrayElements.hpp ${BASE} > ${FILENAME}
	GetArrayElements_CPP ${BASE} float asFloat >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	GetArrayElements_CPP ${BASE} double asDouble >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_shared_ptr_float.cpp
	Header GetArrayElements_shared_ptr.hpp ${BASE} > ${FILENAME}
	GetArrayElements_shared_ptr_CPP ${BASE} float asFloat >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	GetArrayElements_shared_ptr_CPP ${BASE} double asDouble >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_bool.cpp
	Header GetArrayElements.hpp ${BASE} > ${FILENAME}
	GetArrayElements_CPP ${BASE} bool asBool >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_shared_ptr_bool.cpp
	Header GetArrayElements_shared_ptr.hpp ${BASE} > ${FILENAME}
	GetArrayElements_shared_ptr_CPP ${BASE} bool asBool >> ${FILENAME}
	Footer >> ${FILENAME}

}

GetArrayElements_BASE_CPP vector
GetArrayElements_BASE_CPP list
