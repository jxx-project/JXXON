#!/bin/bash

function SetProperty_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_SetProperty_INCLUDED
#define JXXON_Accessor_SetProperty_INCLUDED

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"

namespace JXXON { namespace Accessor {

template<typename T>
SetProperty<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::
		type>::SetProperty(Json& json, const std::string& name) :
	json(json),
	name(name)
{
	json.setTypeObject();
}

template<typename T>
void SetProperty<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()(const T& value)
{
	json.pimpl->getObject().set(name, Poco::Dynamic::Var(value));
}

}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_SetProperty_INCLUDED
EOF
}

SetProperty_TCC > SetProperty.tcc

function SetProperty_shared_ptr_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_SetProperty_shared_ptr_INCLUDED
#define JXXON_Accessor_SetProperty_shared_ptr_INCLUDED

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"

namespace JXXON { namespace Accessor {

template<typename T>
SetProperty<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::
		type>::SetProperty(Json& json, const std::string& name) :
	json(json),
	name(name)
{
	json.setTypeObject();
}

template<typename T>
void SetProperty<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()(const T& value)
{
	if (value) {
		json.pimpl->getObject().set(name, Poco::Dynamic::Var(*value));
	}
}

}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_SetProperty_shared_ptr_INCLUDED
EOF
}

SetProperty_shared_ptr_TCC > SetProperty_shared_ptr.tcc

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

function SetProperty_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template SetProperty<{{ELEMENT_TYPE}}>::SetProperty(Json& json, const std::string& name);
template void SetProperty<{{ELEMENT_TYPE}}>::operator()(const {{ELEMENT_TYPE}}& value);
EOF
}

function SetProperty_shared_ptr_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template SetProperty<std::shared_ptr<{{ELEMENT_TYPE}}>>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::shared_ptr<{{ELEMENT_TYPE}}>>::operator()(const std::shared_ptr<{{ELEMENT_TYPE}}>& value);
EOF
}

function Footer {
cat << EOF

}} // namespace JXXON::Accessor
EOF
}

FILENAME=SetProperty_string.cpp
Header SetProperty.tcc > ${FILENAME}
SetProperty_CPP std::string >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetProperty_shared_ptr_string.cpp
Header SetProperty_shared_ptr.tcc > ${FILENAME}
SetProperty_shared_ptr_CPP std::string >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetProperty_int.cpp
Header SetProperty.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_INT8_T + 0)
EOF
SetProperty_CPP std::int8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT16_T + 0)
EOF
SetProperty_CPP std::int16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT32_T + 0)
EOF
SetProperty_CPP std::int32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT64_T + 0)
EOF
SetProperty_CPP std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INTMAX_T + 0) && \\
	!((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || \\
	  (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
EOF
SetProperty_CPP std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetProperty_shared_ptr_int.cpp
Header SetProperty_shared_ptr.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_INT8_T + 0)
EOF
SetProperty_shared_ptr_CPP std::int8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT16_T + 0)
EOF
SetProperty_shared_ptr_CPP std::int16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT32_T + 0)
EOF
SetProperty_shared_ptr_CPP std::int32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT64_T + 0)
EOF
SetProperty_shared_ptr_CPP std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INTMAX_T + 0) && \\
	!((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || \\
	  (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
EOF
SetProperty_shared_ptr_CPP std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetProperty_unsigned_int.cpp
Header SetProperty.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_UINT8_T + 0)
EOF
SetProperty_CPP std::uint8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT16_T + 0)
EOF
SetProperty_CPP std::uint16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT32_T + 0)
EOF
SetProperty_CPP std::uint32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT64_T + 0)
EOF
SetProperty_CPP std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINTMAX_T + 0) && \\
	!((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || \\
	  (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
EOF
SetProperty_CPP std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetProperty_shared_ptr_unsigned_int.cpp
Header SetProperty_shared_ptr.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_UINT8_T + 0)
EOF
SetProperty_shared_ptr_CPP std::uint8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT16_T + 0)
EOF
SetProperty_shared_ptr_CPP std::uint16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT32_T + 0)
EOF
SetProperty_shared_ptr_CPP std::uint32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT64_T + 0)
EOF
SetProperty_shared_ptr_CPP std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINTMAX_T + 0) && \\
	!((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || \\
	  (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
EOF
SetProperty_shared_ptr_CPP std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetProperty_float.cpp
Header SetProperty.tcc > ${FILENAME}
SetProperty_CPP float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
SetProperty_CPP double >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetProperty_shared_ptr_float.cpp
Header SetProperty_shared_ptr.tcc > ${FILENAME}
SetProperty_shared_ptr_CPP float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
SetProperty_shared_ptr_CPP double >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetProperty_bool.cpp
Header SetProperty.tcc > ${FILENAME}
SetProperty_CPP bool >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetProperty_shared_ptr_bool.cpp
Header SetProperty_shared_ptr.tcc > ${FILENAME}
SetProperty_shared_ptr_CPP bool >> ${FILENAME}
Footer >> ${FILENAME}
