#!/bin/bash

function GetArrayElements_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_GetArrayElements_INCLUDED
#define JXXON_Accessor_GetArrayElements_INCLUDED

namespace JXXON { namespace Accessor {
namespace {

template<typename T>
void populateArray(Json::ArrayType<T>& array, const ::Json::Value& value, const std::function<T(const ::Json::Value&)>& valueAsT)
{
	if (!value.isNull()) {
		if (value.isArray()) {
			try {
				for (const auto& i : value) {
					array.addElement(i.isNull() ?  T() : T(valueAsT(i)));
				}
			} catch (std::exception& e) {
				throw Error(e.what());
			}
		} else {
			throw Error("Not an array");
		}
	}
}

} // namespace
}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_GetArrayElements_INCLUDED
EOF
}

GetArrayElements_TCC > GetArrayElements.tcc

function GetArrayElements_shared_ptr_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED
#define JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED

namespace JXXON { namespace Accessor {
namespace {

template<typename T>
void populateArray(Json::ArrayType<T>& array, const ::Json::Value& value, const std::function<typename T::element_type(const ::Json::Value&)>& valueAsT)
{
	if (!value.isNull()) {
		if (value.isArray()) {
			try {
				for (const auto& i : value) {
					array.addElement(i.isNull() ? T() : std::make_shared<typename T::element_type>(valueAsT(i)));
				}
			} catch (std::exception& e) {
				throw Error(e.what());
			}
		} else {
			throw Error("Not an array");
		}
	}
}

} // namespace
}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED
EOF
}

GetArrayElements_shared_ptr_TCC > GetArrayElements_shared_ptr.tcc

function Header {
cat << EOF | sed "s/{{INCLUDE}}/$1/g"
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/{{INCLUDE}}"
#include <cstdint>

namespace JXXON { namespace Accessor {

EOF
}

function GetArrayElements_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g" | sed "s/{{AS_TYPE}}/$2/g"
template<>
GetArrayElements<{{ELEMENT_TYPE}}>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<{{ELEMENT_TYPE}}>::operator()(Json::ArrayType<{{ELEMENT_TYPE}}>& array) const
{
	populateArray<{{ELEMENT_TYPE}}>(array, json.pimpl->value, [](const ::Json::Value& value){return value.{{AS_TYPE}}();});
}

template GetArrayElements<{{ELEMENT_TYPE}}>::GetArrayElements(const Json& json);
template void GetArrayElements<{{ELEMENT_TYPE}}>::operator()(Json::ArrayType<{{ELEMENT_TYPE}}>& array) const;
EOF
}

function GetArrayElements_shared_ptr_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g" | sed "s/{{AS_TYPE}}/$2/g"
template<>
GetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>>::operator()(Json::ArrayType<std::shared_ptr<{{ELEMENT_TYPE}}>>& array) const
{
	populateArray<std::shared_ptr<{{ELEMENT_TYPE}}>>(array, json.pimpl->value, [](const ::Json::Value& value){return value.{{AS_TYPE}}();});
}

template GetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>>::operator()(Json::ArrayType<std::shared_ptr<{{ELEMENT_TYPE}}>>& array) const;
EOF
}

function Footer {
cat << EOF

}} // namespace JXXON::Accessor
EOF
}


FILENAME=GetArrayElements_string.cpp
Header GetArrayElements.tcc > ${FILENAME}
GetArrayElements_CPP std::string asString >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetArrayElements_shared_ptr_string.cpp
Header GetArrayElements_shared_ptr.tcc > ${FILENAME}
GetArrayElements_shared_ptr_CPP std::string asString >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetArrayElements_int.cpp
Header GetArrayElements.tcc > ${FILENAME}
GetArrayElements_CPP int asInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
GetArrayElements_CPP std::int64_t asInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
GetArrayElements_CPP std::intmax_t asLargestInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetArrayElements_shared_ptr_int.cpp
Header GetArrayElements_shared_ptr.tcc > ${FILENAME}
GetArrayElements_shared_ptr_CPP int asInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
GetArrayElements_shared_ptr_CPP std::int64_t asInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
GetArrayElements_shared_ptr_CPP std::intmax_t asLargestInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetArrayElements_unsigned_int.cpp
Header GetArrayElements.tcc > ${FILENAME}
GetArrayElements_CPP 'unsigned int' asUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
GetArrayElements_CPP std::uint64_t asUInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
GetArrayElements_CPP std::uintmax_t asLargestUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetArrayElements_shared_ptr_unsigned_int.cpp
Header GetArrayElements_shared_ptr.tcc > ${FILENAME}
GetArrayElements_shared_ptr_CPP 'unsigned int' asUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
GetArrayElements_shared_ptr_CPP std::uint64_t asUInt64 >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
GetArrayElements_shared_ptr_CPP std::uintmax_t asLargestUInt >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetArrayElements_float.cpp
Header GetArrayElements.tcc > ${FILENAME}
GetArrayElements_CPP float asFloat >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
GetArrayElements_CPP double asDouble >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetArrayElements_shared_ptr_float.cpp
Header GetArrayElements_shared_ptr.tcc > ${FILENAME}
GetArrayElements_shared_ptr_CPP float asFloat >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
GetArrayElements_shared_ptr_CPP double asDouble >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetArrayElements_bool.cpp
Header GetArrayElements.tcc > ${FILENAME}
GetArrayElements_CPP bool asBool >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetArrayElements_shared_ptr_bool.cpp
Header GetArrayElements_shared_ptr.tcc > ${FILENAME}
GetArrayElements_shared_ptr_CPP bool asBool >> ${FILENAME}
Footer >> ${FILENAME}
