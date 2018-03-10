#!/bin/sh

function SetProperty_HPP {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_SetProperty_INCLUDED
#define JXXON_Accessor_SetProperty_INCLUDED

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"

namespace JXXON {
namespace Accessor {

template<typename T>
SetProperty<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::SetProperty(Json& json, const std::string& name) : json(json), name(name)
{
	json.setTypeObject();
}

template<typename T>
void SetProperty<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()(const T& value)
{
	Poco::Dynamic::Var child(value);
	json.pimpl->getObject()->set(name, child);
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_SetProperty_INCLUDED
EOF
}

SetProperty_HPP > SetProperty.hpp

function SetProperty_shared_ptr_HPP {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_SetProperty_shared_ptr_INCLUDED
#define JXXON_Accessor_SetProperty_shared_ptr_INCLUDED

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"

namespace JXXON {
namespace Accessor {

template<typename T>
SetProperty<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::SetProperty(Json& json, const std::string& name) : json(json), name(name)
{
	json.setTypeObject();
}

template<typename T>
void SetProperty<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()(const T& value)
{
	if (value) {
		Poco::Dynamic::Var child(*value);
		json.pimpl->getObject()->set(name, child);
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_SetProperty_shared_ptr_INCLUDED
EOF
}

SetProperty_shared_ptr_HPP > SetProperty_shared_ptr.hpp

function Header {
cat << EOF | sed "s/{{INCLUDE}}/$1/g"
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/{{INCLUDE}}"

namespace JXXON {
namespace Accessor {

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
template SetProperty< std::shared_ptr<{{ELEMENT_TYPE}}> >::SetProperty(Json& json, const std::string& name);
template void SetProperty< std::shared_ptr<{{ELEMENT_TYPE}}> >::operator()(const std::shared_ptr<{{ELEMENT_TYPE}}>& value);
EOF
}

function Footer {
cat << EOF

} // namespace Accessor
} // namespace JXXON
EOF
}

FILENAME=SetProperty_string.cpp
Header SetProperty.hpp > ${FILENAME}
SetProperty_CPP std::string >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetProperty_shared_ptr_string.cpp
Header SetProperty_shared_ptr.hpp > ${FILENAME}
SetProperty_shared_ptr_CPP std::string >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetProperty_int.cpp
Header SetProperty.hpp > ${FILENAME}
SetProperty_CPP int >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
SetProperty_CPP std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
SetProperty_CPP std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetProperty_shared_ptr_int.cpp
Header SetProperty_shared_ptr.hpp > ${FILENAME}
SetProperty_shared_ptr_CPP int >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
SetProperty_shared_ptr_CPP std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
SetProperty_shared_ptr_CPP std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetProperty_unsigned_int.cpp
Header SetProperty.hpp > ${FILENAME}
SetProperty_CPP 'unsigned int' >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
SetProperty_CPP std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
SetProperty_CPP std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetProperty_shared_ptr_unsigned_int.cpp
Header SetProperty_shared_ptr.hpp > ${FILENAME}
SetProperty_shared_ptr_CPP 'unsigned int' >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
SetProperty_shared_ptr_CPP std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
SetProperty_shared_ptr_CPP std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
Footer >> ${FILENAME}


FILENAME=SetProperty_float.cpp
Header SetProperty.hpp > ${FILENAME}
SetProperty_CPP float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
SetProperty_CPP double >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetProperty_shared_ptr_float.cpp
Header SetProperty_shared_ptr.hpp > ${FILENAME}
SetProperty_shared_ptr_CPP float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
SetProperty_shared_ptr_CPP double >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetProperty_bool.cpp
Header SetProperty.hpp > ${FILENAME}
SetProperty_CPP bool >> ${FILENAME}
Footer >> ${FILENAME}


FILENAME=SetProperty_shared_ptr_bool.cpp
Header SetProperty_shared_ptr.hpp > ${FILENAME}
SetProperty_shared_ptr_CPP bool >> ${FILENAME}
Footer >> ${FILENAME}
