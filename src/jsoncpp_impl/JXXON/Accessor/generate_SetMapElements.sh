#!/bin/bash

function SetMapElements_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_SetMapElements_INCLUDED
#define JXXON_Accessor_SetMapElements_INCLUDED

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"

namespace JXXON { namespace Accessor {

template<typename T>
SetMapElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::SetMapElements(Json& json) :
	json(json)
{
	json.setTypeObject();
}

template<typename T>
void SetMapElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()(const Json::MapType<T>& map)
{
	map.forEach([&](const std::string& key, const T& value) { json.pimpl->value[key] = value; });
}

}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_SetMapElements_INCLUDED
EOF
}

SetMapElements_TCC > SetMapElements.tcc

function SetMapElements_shared_ptr_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_SetMapElements_shared_ptr_INCLUDED
#define JXXON_Accessor_SetMapElements_shared_ptr_INCLUDED

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"

namespace JXXON { namespace Accessor {

template<typename T>
SetMapElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::SetMapElements(Json& json) :
	json(json)
{
	json.setTypeObject();
}

template<typename T>
void SetMapElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()(const Json::MapType<T>& map)
{
	map.forEach([&](const std::string& key, const T& value) { json.pimpl->value[key] = value ? *value : ::Json::Value::null; });
}

}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_SetMapElements_shared_ptr_INCLUDED
EOF
}

SetMapElements_shared_ptr_TCC > SetMapElements_shared_ptr.tcc

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

function SetMapElements_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template SetMapElements<{{ELEMENT_TYPE}}>::SetMapElements(Json& json);
template void SetMapElements<{{ELEMENT_TYPE}}>::operator()(const Json::MapType<{{ELEMENT_TYPE}}>& map);
EOF
}

function SetMapElements_shared_ptr_CPP {
cat << EOF | sed "s/{{ELEMENT_TYPE}}/$1/g"
template SetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>>::operator()(const Json::MapType<std::shared_ptr<{{ELEMENT_TYPE}}>>& map);
EOF
}

function Footer {
cat << EOF

}} // namespace JXXON::Accessor
EOF
}


FILENAME=SetMapElements_string.cpp
Header SetMapElements.tcc > ${FILENAME}
SetMapElements_CPP std::string >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetMapElements_shared_ptr_string.cpp
Header SetMapElements_shared_ptr.tcc > ${FILENAME}
SetMapElements_shared_ptr_CPP std::string >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetMapElements_int.cpp
Header SetMapElements.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_INT8_T + 0)
EOF
SetMapElements_CPP std::int8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT16_T + 0)
EOF
SetMapElements_CPP std::int16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT32_T + 0)
EOF
SetMapElements_CPP std::int32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT64_T + 0)
EOF
SetMapElements_CPP std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INTMAX_T + 0) && \\
	!((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || \\
	  (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
EOF
SetMapElements_CPP std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetMapElements_shared_ptr_int.cpp
Header SetMapElements_shared_ptr.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_INT8_T + 0)
EOF
SetMapElements_shared_ptr_CPP std::int8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT16_T + 0)
EOF
SetMapElements_shared_ptr_CPP std::int16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT32_T + 0)
EOF
SetMapElements_shared_ptr_CPP std::int32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INT64_T + 0)
EOF
SetMapElements_shared_ptr_CPP std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_INTMAX_T + 0) && \\
	!((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || \\
	  (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
EOF
SetMapElements_shared_ptr_CPP std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetMapElements_unsigned_int.cpp
Header SetMapElements.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_UINT8_T + 0)
EOF
SetMapElements_CPP std::uint8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT16_T + 0)
EOF
SetMapElements_CPP std::uint16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT32_T + 0)
EOF
SetMapElements_CPP std::uint32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT64_T + 0)
EOF
SetMapElements_CPP std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINTMAX_T + 0) && \\
	!((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || \\
	  (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
EOF
SetMapElements_CPP std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetMapElements_shared_ptr_unsigned_int.cpp
Header SetMapElements_shared_ptr.tcc > ${FILENAME}
cat << EOF >> ${FILENAME}

#if (_SIZEOF_UINT8_T + 0)
EOF
SetMapElements_shared_ptr_CPP std::uint8_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT16_T + 0)
EOF
SetMapElements_shared_ptr_CPP std::uint16_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT32_T + 0)
EOF
SetMapElements_shared_ptr_CPP std::uint32_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINT64_T + 0)
EOF
SetMapElements_shared_ptr_CPP std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if (_SIZEOF_UINTMAX_T + 0) && \\
	!((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || \\
	  (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
EOF
SetMapElements_shared_ptr_CPP std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetMapElements_float.cpp
Header SetMapElements.tcc > ${FILENAME}
SetMapElements_CPP float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
SetMapElements_CPP double >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetMapElements_shared_ptr_float.cpp
Header SetMapElements_shared_ptr.tcc > ${FILENAME}
SetMapElements_shared_ptr_CPP float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
SetMapElements_shared_ptr_CPP double >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetMapElements_bool.cpp
Header SetMapElements.tcc > ${FILENAME}
SetMapElements_CPP bool >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetMapElements_shared_ptr_bool.cpp
Header SetMapElements_shared_ptr.tcc > ${FILENAME}
SetMapElements_shared_ptr_CPP bool >> ${FILENAME}
Footer >> ${FILENAME}
