#!/bin/bash

function SetArrayElements_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_SetArrayElements_INCLUDED
#define JXXON_Accessor_SetArrayElements_INCLUDED

namespace JXXON { namespace Accessor {

template<typename T>
SetArrayElements<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::SetArrayElements(Json& json) : json(json)
{
	json.setTypeArray();
}

template<typename T>
void SetArrayElements<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()(const Json::ArrayType<T>& array)
{
	array.forEach([&](const T& element){json.pimpl->value.append(::Json::Value(element));});
}

}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_SetArrayElements_INCLUDED
EOF
}

SetArrayElements_TCC > SetArrayElements.tcc

function SetArrayElements_shared_ptr_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_SetArrayElements_shared_ptr_INCLUDED
#define JXXON_Accessor_SetArrayElements_shared_ptr_INCLUDED

namespace JXXON { namespace Accessor {

template<typename T>
SetArrayElements<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::SetArrayElements(Json& json) : json(json)
{
	json.setTypeArray();
}

template<typename T>
void SetArrayElements<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()(const Json::ArrayType<T>& array)
{
	array.forEach([&](const T& element){json.pimpl->value.append(element ? ::Json::Value(*element) : ::Json::Value::null);});
}

}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_SetArrayElements_shared_ptr_INCLUDED
EOF
}

SetArrayElements_shared_ptr_TCC > SetArrayElements_shared_ptr.tcc

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

function SetArrayElements_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template SetArrayElements<{{ELEMENT_TYPE}}>::SetArrayElements(Json& json);
template void SetArrayElements<{{ELEMENT_TYPE}}>::operator()(const Json::ArrayType<{{ELEMENT_TYPE}}>& array);
EOF
}

function SetArrayElements_shared_ptr_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template SetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>>::operator()(const Json::ArrayType<std::shared_ptr<{{ELEMENT_TYPE}}>>& array);
EOF
}

function Footer {
cat << EOF

}} // namespace JXXON::Accessor
EOF
}


FILENAME=SetArrayElements_string.cpp
Header SetArrayElements.tcc > ${FILENAME}
SetArrayElements_CPP std::string >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetArrayElements_shared_ptr_string.cpp
Header SetArrayElements_shared_ptr.tcc > ${FILENAME}
SetArrayElements_shared_ptr_CPP std::string >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetArrayElements_int.cpp
Header SetArrayElements.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_INT8_T + 0)
EOF
SetArrayElements_CPP std::int8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT16_T + 0)
EOF
SetArrayElements_CPP std::int16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT32_T + 0)
EOF
SetArrayElements_CPP std::int32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT64_T + 0)
EOF
SetArrayElements_CPP std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INTMAX_T + 0) && !((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
EOF
SetArrayElements_CPP std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetArrayElements_shared_ptr_int.cpp
Header SetArrayElements_shared_ptr.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_INT8_T + 0)
EOF
SetArrayElements_shared_ptr_CPP std::int8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT16_T + 0)
EOF
SetArrayElements_shared_ptr_CPP std::int16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT32_T + 0)
EOF
SetArrayElements_shared_ptr_CPP std::int32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT64_T + 0)
EOF
SetArrayElements_shared_ptr_CPP std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INTMAX_T + 0) && !((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
EOF
SetArrayElements_shared_ptr_CPP std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetArrayElements_unsigned_int.cpp
Header SetArrayElements.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_UINT8_T + 0)
EOF
SetArrayElements_CPP std::uint8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT16_T + 0)
EOF
SetArrayElements_CPP std::uint16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT32_T + 0)
EOF
SetArrayElements_CPP std::uint32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT64_T + 0)
EOF
SetArrayElements_CPP std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINTMAX_T + 0) && !((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
EOF
SetArrayElements_CPP std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetArrayElements_shared_ptr_unsigned_int.cpp
Header SetArrayElements_shared_ptr.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_UINT8_T + 0)
EOF
SetArrayElements_shared_ptr_CPP std::uint8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT16_T + 0)
EOF
SetArrayElements_shared_ptr_CPP std::uint16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT32_T + 0)
EOF
SetArrayElements_shared_ptr_CPP std::uint32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT64_T + 0)
EOF
SetArrayElements_shared_ptr_CPP std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINTMAX_T + 0) && !((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
EOF
SetArrayElements_shared_ptr_CPP std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetArrayElements_float.cpp
Header SetArrayElements.tcc > ${FILENAME}
SetArrayElements_CPP float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
SetArrayElements_CPP double >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetArrayElements_shared_ptr_float.cpp
Header SetArrayElements_shared_ptr.tcc > ${FILENAME}
SetArrayElements_shared_ptr_CPP float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
SetArrayElements_shared_ptr_CPP double >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetArrayElements_bool.cpp
Header SetArrayElements.tcc > ${FILENAME}
SetArrayElements_CPP bool >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetArrayElements_shared_ptr_bool.cpp
Header SetArrayElements_shared_ptr.tcc > ${FILENAME}
SetArrayElements_shared_ptr_CPP bool >> ${FILENAME}
Footer >> ${FILENAME}
