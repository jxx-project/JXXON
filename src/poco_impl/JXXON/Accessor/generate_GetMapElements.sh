#!/bin/bash

function GetMapElements_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_GetMapElements_INCLUDED
#define JXXON_Accessor_GetMapElements_INCLUDED

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"

namespace JXXON { namespace Accessor {

template<typename T>
GetMapElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::GetMapElements(const Json& json) :
	json(json)
{
}

template<typename T>
void GetMapElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()(Json::MapType<T>& map) const
{
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getObject()) {
				map.addElement(i.first, i.second.isEmpty() ? T() : i.second.convert<T>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

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
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_GetMapElements_shared_ptr_INCLUDED
#define JXXON_Accessor_GetMapElements_shared_ptr_INCLUDED

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"

namespace JXXON { namespace Accessor {

template<typename T>
GetMapElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::GetMapElements(const Json& json) :
	json(json)
{
}

template<typename T>
void GetMapElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()(Json::MapType<T>& map) const
{
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getObject()) {
				map.addElement(
					i.first,
					i.second.isEmpty() ? T() :
										 std::make_shared<typename T::element_type>(i.second.convert<typename T::element_type>()));
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_GetMapElements_shared_ptr_INCLUDED
EOF
}

GetMapElements_shared_ptr_TCC > GetMapElements_shared_ptr.tcc

function GetMapElements_SPECIALIZATION {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template<>
void GetMapElements<{{ELEMENT_TYPE}}>::operator()(Json::MapType<{{ELEMENT_TYPE}}>& map) const
{
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getObject()) {
				map.addElement(i.first, i.second.isEmpty() ? {{ELEMENT_TYPE}}() : i.second.extract<{{ELEMENT_TYPE}}>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

EOF
}

function GetMapElements_shared_ptr_SPECIALIZATION {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template<>
void GetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>>::operator()(Json::MapType<std::shared_ptr<{{ELEMENT_TYPE}}>>& map) const
{
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getObject()) {
				map.addElement(i.first, i.second.isEmpty() ? nullptr : std::make_shared<{{ELEMENT_TYPE}}>(i.second.extract<{{ELEMENT_TYPE}}>()));
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
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/{{INCLUDE}}"
#include <cstdint>

namespace JXXON { namespace Accessor {

EOF
}

function GetMapElements_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template GetMapElements<{{ELEMENT_TYPE}}>::GetMapElements(const Json& json);
template void GetMapElements<{{ELEMENT_TYPE}}>::operator()(Json::MapType<{{ELEMENT_TYPE}}>& map) const;
EOF
}

function GetMapElements_shared_ptr_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template GetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>>::operator()(Json::MapType<std::shared_ptr<{{ELEMENT_TYPE}}>>& map) const;
EOF
}

function Footer {
cat << EOF

}} // namespace JXXON::Accessor
EOF
}


FILENAME=GetMapElements_string.cpp
Header GetMapElements.tcc > ${FILENAME}
GetMapElements_SPECIALIZATION std::string >> ${FILENAME}
GetMapElements_CPP std::string >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetMapElements_shared_ptr_string.cpp
Header GetMapElements_shared_ptr.tcc > ${FILENAME}
GetMapElements_shared_ptr_SPECIALIZATION std::string >> ${FILENAME}
GetMapElements_shared_ptr_CPP std::string >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetMapElements_int.cpp
Header GetMapElements.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_INT8_T + 0)
EOF
GetMapElements_CPP std::int8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT16_T + 0)
EOF
GetMapElements_CPP std::int16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT32_T + 0)
EOF
GetMapElements_CPP std::int32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT64_T + 0)
EOF
GetMapElements_CPP std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INTMAX_T + 0) && \\
	!((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || \\
	  (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
EOF
GetMapElements_CPP std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetMapElements_shared_ptr_int.cpp
Header GetMapElements_shared_ptr.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_INT8_T + 0)
EOF
GetMapElements_shared_ptr_CPP std::int8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT16_T + 0)
EOF
GetMapElements_shared_ptr_CPP std::int16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT32_T + 0)
EOF
GetMapElements_shared_ptr_CPP std::int32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT64_T + 0)
EOF
GetMapElements_shared_ptr_CPP std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INTMAX_T + 0) && \\
	!((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || \\
	  (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
EOF
GetMapElements_shared_ptr_CPP std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetMapElements_unsigned_int.cpp
Header GetMapElements.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_UINT8_T + 0)
EOF
GetMapElements_CPP std::uint8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT16_T + 0)
EOF
GetMapElements_CPP std::uint16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT32_T + 0)
EOF
GetMapElements_CPP std::uint32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT64_T + 0)
EOF
GetMapElements_CPP std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINTMAX_T + 0) && \\
	!((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || \\
	  (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
EOF
GetMapElements_CPP std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetMapElements_shared_ptr_unsigned_int.cpp
Header GetMapElements_shared_ptr.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_UINT8_T + 0)
EOF
GetMapElements_shared_ptr_CPP std::uint8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT16_T + 0)
EOF
GetMapElements_shared_ptr_CPP std::uint16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT32_T + 0)
EOF
GetMapElements_shared_ptr_CPP std::uint32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT64_T + 0)
EOF
GetMapElements_shared_ptr_CPP std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINTMAX_T + 0) && \\
	!((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || \\
	  (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
EOF
GetMapElements_shared_ptr_CPP std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=GetMapElements_float.cpp
Header GetMapElements.tcc > ${FILENAME}
GetMapElements_CPP float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
GetMapElements_CPP double >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetMapElements_shared_ptr_float.cpp
Header GetMapElements_shared_ptr.tcc > ${FILENAME}
GetMapElements_shared_ptr_CPP float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
GetMapElements_shared_ptr_CPP double >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetMapElements_bool.cpp
Header GetMapElements.tcc > ${FILENAME}
GetMapElements_SPECIALIZATION bool >> ${FILENAME}
GetMapElements_CPP bool >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=GetMapElements_shared_ptr_bool.cpp
Header GetMapElements_shared_ptr.tcc > ${FILENAME}
GetMapElements_shared_ptr_SPECIALIZATION bool >> ${FILENAME}
GetMapElements_shared_ptr_CPP bool >> ${FILENAME}
Footer >> ${FILENAME}
