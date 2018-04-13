#!/bin/bash

function GetArrayElements_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetArrayElements_INCLUDED
#define JXXON_Accessor_GetArrayElements_INCLUDED

namespace JXXON { namespace Accessor {

template<typename T>
GetArrayElements<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::GetArrayElements(const Json& json) : json(json)
{
}

template<typename T>
void GetArrayElements<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()(Json::ArrayType<T>& array) const
{
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getArray()) {
				array.addElement(i.isEmpty() ? T() : i.convert<T>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

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
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED
#define JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED

namespace JXXON { namespace Accessor {

template<typename T>
GetArrayElements<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::GetArrayElements(const Json& json) : json(json)
{
}

template<typename T>
void GetArrayElements<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()(Json::ArrayType<T>& array) const
{
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getArray()) {
				array.addElement(i.isEmpty() ? nullptr : std::make_shared<typename T::element_type>(i.convert<typename T::element_type>()));
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED
EOF
}

GetArrayElements_shared_ptr_TCC > GetArrayElements_shared_ptr.tcc

function GetArrayElements_SPECIALIZATION {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template<>
void GetArrayElements<{{ELEMENT_TYPE}}>::operator()(Json::ArrayType<{{ELEMENT_TYPE}}>& array) const
{
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getArray()) {
				array.addElement(i.isEmpty() ? {{ELEMENT_TYPE}}() : i.extract<{{ELEMENT_TYPE}}>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

EOF
}

function GetArrayElements_shared_ptr_SPECIALIZATION {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template<>
void GetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>>::operator()(Json::ArrayType<std::shared_ptr<{{ELEMENT_TYPE}}>>& array) const
{
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getArray()) {
				array.addElement(i.isEmpty() ? nullptr : std::make_shared<{{ELEMENT_TYPE}}>(i.extract<{{ELEMENT_TYPE}}>()));
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

EOF
}

function Header {
cat << EOF | sed "s/{{INCLUDE}}/$1/g"
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
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
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template GetArrayElements<{{ELEMENT_TYPE}}>::GetArrayElements(const Json& json);
template void GetArrayElements<{{ELEMENT_TYPE}}>::operator()(Json::ArrayType<{{ELEMENT_TYPE}}>& array) const;
EOF
}

function GetArrayElements_shared_ptr_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
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
GetArrayElements_SPECIALIZATION std::string >> ${FILENAME}
GetArrayElements_CPP std::string >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetArrayElements_shared_ptr_string.cpp
Header GetArrayElements_shared_ptr.tcc > ${FILENAME}
GetArrayElements_shared_ptr_SPECIALIZATION std::string >> ${FILENAME}
GetArrayElements_shared_ptr_CPP std::string >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetArrayElements_int.cpp
Header GetArrayElements.tcc > ${FILENAME}
GetArrayElements_CPP int >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
GetArrayElements_CPP std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
GetArrayElements_CPP std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetArrayElements_shared_ptr_int.cpp
Header GetArrayElements_shared_ptr.tcc > ${FILENAME}
GetArrayElements_shared_ptr_CPP int >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
GetArrayElements_shared_ptr_CPP std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
GetArrayElements_shared_ptr_CPP std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetArrayElements_unsigned_int.cpp
Header GetArrayElements.tcc > ${FILENAME}
GetArrayElements_CPP 'unsigned int' >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
GetArrayElements_CPP std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
GetArrayElements_CPP std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetArrayElements_shared_ptr_unsigned_int.cpp
Header GetArrayElements_shared_ptr.tcc > ${FILENAME}
GetArrayElements_shared_ptr_CPP 'unsigned int' >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
GetArrayElements_shared_ptr_CPP std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
GetArrayElements_shared_ptr_CPP std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetArrayElements_float.cpp
Header GetArrayElements.tcc > ${FILENAME}
GetArrayElements_CPP float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
GetArrayElements_CPP double >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetArrayElements_shared_ptr_float.cpp
Header GetArrayElements_shared_ptr.tcc > ${FILENAME}
GetArrayElements_shared_ptr_CPP float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
GetArrayElements_shared_ptr_CPP double >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetArrayElements_bool.cpp
Header GetArrayElements.tcc > ${FILENAME}
GetArrayElements_SPECIALIZATION bool >> ${FILENAME}
GetArrayElements_CPP bool >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetArrayElements_shared_ptr_bool.cpp
Header GetArrayElements_shared_ptr.tcc > ${FILENAME}
GetArrayElements_shared_ptr_SPECIALIZATION bool >> ${FILENAME}
GetArrayElements_shared_ptr_CPP bool >> ${FILENAME}
Footer >> ${FILENAME}
