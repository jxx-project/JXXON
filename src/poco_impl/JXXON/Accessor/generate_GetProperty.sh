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

namespace JXXON { namespace Accessor {

template<typename T>
GetProperty<T,  typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<typename T>
T GetProperty<T,  typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()() const
{
	if (json.pimpl) {
		try {
			auto child = json.pimpl->getObject().get(name);
			if (!child.isEmpty()) {
				return child.convert<T>();
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
	return T();
}

}} // namespace JXXON::Accessor

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

namespace JXXON { namespace Accessor {

template<typename T>
GetProperty<T,  typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<typename T>
T GetProperty<T,  typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()() const
{
	if (json.pimpl) {
		try {
			auto child = json.pimpl->getObject().get(name);
			if (!child.isEmpty()) {
				return std::make_shared<typename T::element_type>(child.convert<typename T::element_type>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
	return nullptr;
}

}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_GetProperty_shared_ptr_INCLUDED
EOF
}

GetProperty_shared_ptr_TCC > GetProperty_shared_ptr.tcc

function GetProperty_SPECIALIZATION {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template<>
{{ELEMENT_TYPE}} GetProperty<{{ELEMENT_TYPE}}>::operator()() const
{
	if (json.pimpl) {
		try {
			auto child = json.pimpl->getObject().get(name);
			if (!child.isEmpty()) {
				return child.extract<{{ELEMENT_TYPE}}>();
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
	return {{ELEMENT_TYPE}}();
}

EOF
}

function GetProperty_shared_ptr_SPECIALIZATION {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template<>
std::shared_ptr<{{ELEMENT_TYPE}}> GetProperty<std::shared_ptr<{{ELEMENT_TYPE}}>>::operator()() const
{
	if (json.pimpl) {
		try {
			auto child = json.pimpl->getObject().get(name);
			if (!child.isEmpty()) {
				return std::make_shared<{{ELEMENT_TYPE}}>(child.extract<{{ELEMENT_TYPE}}>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
	return nullptr;
}

EOF
}

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

function GetProperty_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template GetProperty<{{ELEMENT_TYPE}}>::GetProperty(const Json& json, const std::string& name);
template {{ELEMENT_TYPE}} GetProperty<{{ELEMENT_TYPE}}>::operator()() const;
EOF
}

function GetProperty_shared_ptr_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
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
GetProperty_SPECIALIZATION std::string >> ${FILENAME}
GetProperty_CPP std::string >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetProperty_shared_ptr_string.cpp
Header GetProperty_shared_ptr.tcc > ${FILENAME}
GetProperty_shared_ptr_SPECIALIZATION std::string >> ${FILENAME}
GetProperty_shared_ptr_CPP std::string >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetProperty_int.cpp
Header GetProperty.tcc > ${FILENAME}
GetProperty_CPP int >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
GetProperty_CPP std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
GetProperty_CPP std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetProperty_shared_ptr_int.cpp
Header GetProperty_shared_ptr.tcc > ${FILENAME}
GetProperty_shared_ptr_CPP int >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
GetProperty_shared_ptr_CPP std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
GetProperty_shared_ptr_CPP std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetProperty_unsigned_int.cpp
Header GetProperty.tcc > ${FILENAME}
GetProperty_CPP 'unsigned int' >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
GetProperty_CPP std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
GetProperty_CPP std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetProperty_shared_ptr_unsigned_int.cpp
Header GetProperty_shared_ptr.tcc > ${FILENAME}
GetProperty_shared_ptr_CPP 'unsigned int' >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
GetProperty_shared_ptr_CPP std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
GetProperty_shared_ptr_CPP std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetProperty_float.cpp
Header GetProperty.tcc > ${FILENAME}
GetProperty_CPP float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
GetProperty_CPP double >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetProperty_shared_ptr_float.cpp
Header GetProperty_shared_ptr.tcc > ${FILENAME}
GetProperty_shared_ptr_CPP float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
GetProperty_shared_ptr_CPP double >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetProperty_bool.cpp
Header GetProperty.tcc > ${FILENAME}
GetProperty_SPECIALIZATION bool >> ${FILENAME}
GetProperty_CPP bool >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetProperty_shared_ptr_bool.cpp
Header GetProperty_shared_ptr.tcc > ${FILENAME}
GetProperty_shared_ptr_SPECIALIZATION bool >> ${FILENAME}
GetProperty_shared_ptr_CPP bool >> ${FILENAME}
Footer >> ${FILENAME}
