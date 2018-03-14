#!/bin/sh

function SetMapElements_HPP {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_SetMapElements_INCLUDED
#define JXXON_Accessor_SetMapElements_INCLUDED

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template<typename T, template<typename...> class Base>
SetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::SetMapElements(Json& json) : json(json)
{
	json.setTypeObject();
}

template<typename T, template<typename...> class Base>
void SetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()(const Json::MapBase<T, Base>& map)
{
	for (auto i = map.begin(); i != map.end(); ++i) {
		json.pimpl->value[i->first] = i->second;
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_SetMapElements_INCLUDED
EOF
}

SetMapElements_HPP > SetMapElements.hpp

function SetMapElements_shared_ptr_HPP {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_SetMapElements_shared_ptr_INCLUDED
#define JXXON_Accessor_SetMapElements_shared_ptr_INCLUDED

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template<typename T, template<typename...> class Base>
SetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::SetMapElements(Json& json) : json(json)
{
	json.setTypeObject();
}

template<typename T, template<typename...> class Base>
void SetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()(const Json::MapBase<T, Base>& map)
{
	for (auto i = map.begin(); i != map.end(); ++i) {
		json.pimpl->value[i->first] = i->second ? *i->second : ::Json::Value::null;
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_SetMapElements_shared_ptr_INCLUDED
EOF
}

SetMapElements_shared_ptr_HPP > SetMapElements_shared_ptr.hpp

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

function SetMapElements_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g"
template SetMapElements<{{ELEMENT_TYPE}}, std::{{BASE}}>::SetMapElements(Json& json);
template void SetMapElements<{{ELEMENT_TYPE}}, std::{{BASE}}>::operator()(const Json::MapBase<{{ELEMENT_TYPE}}, std::{{BASE}}>& map);
EOF
}

function SetMapElements_shared_ptr_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g"
template SetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>::operator()(const Json::MapBase<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>& map);
EOF
}

function Footer {
cat << EOF

} // namespace Accessor
} // namespace JXXON
EOF
}


function SetMapElements_BASE_CPP {

	BASE=$1
	    
	FILENAME=SetMapElements_${BASE}_string.cpp
	Header SetMapElements.hpp ${BASE} > ${FILENAME}
	SetMapElements_CPP ${BASE} std::string >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=SetMapElements_${BASE}_shared_ptr_string.cpp
	Header SetMapElements_shared_ptr.hpp ${BASE} > ${FILENAME}
	SetMapElements_shared_ptr_CPP ${BASE} std::string >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=SetMapElements_${BASE}_int.cpp
	Header SetMapElements.hpp ${BASE} > ${FILENAME}
	SetMapElements_CPP ${BASE} int >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
	SetMapElements_CPP ${BASE} std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
	SetMapElements_CPP ${BASE} std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=SetMapElements_${BASE}_shared_ptr_int.cpp
	Header SetMapElements_shared_ptr.hpp ${BASE} > ${FILENAME}
	SetMapElements_shared_ptr_CPP ${BASE} int >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
	SetMapElements_shared_ptr_CPP ${BASE} std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
	SetMapElements_shared_ptr_CPP ${BASE} std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=SetMapElements_${BASE}_unsigned_int.cpp
	Header SetMapElements.hpp ${BASE} > ${FILENAME}
	SetMapElements_CPP ${BASE} 'unsigned int' >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
	SetMapElements_CPP ${BASE} std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
	SetMapElements_CPP ${BASE} std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=SetMapElements_${BASE}_shared_ptr_unsigned_int.cpp
	Header SetMapElements_shared_ptr.hpp ${BASE} > ${FILENAME}
	SetMapElements_shared_ptr_CPP ${BASE} 'unsigned int' >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
	SetMapElements_shared_ptr_CPP ${BASE} std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
	SetMapElements_shared_ptr_CPP ${BASE} std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=SetMapElements_${BASE}_float.cpp
	Header SetMapElements.hpp ${BASE} > ${FILENAME}
	SetMapElements_CPP ${BASE} float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	SetMapElements_CPP ${BASE} double >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=SetMapElements_${BASE}_shared_ptr_float.cpp
	Header SetMapElements_shared_ptr.hpp ${BASE} > ${FILENAME}
	SetMapElements_shared_ptr_CPP ${BASE} float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	SetMapElements_shared_ptr_CPP ${BASE} double >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=SetMapElements_${BASE}_bool.cpp
	Header SetMapElements.hpp ${BASE} > ${FILENAME}
	SetMapElements_CPP ${BASE} bool >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=SetMapElements_${BASE}_shared_ptr_bool.cpp
	Header SetMapElements_shared_ptr.hpp ${BASE} > ${FILENAME}
	SetMapElements_shared_ptr_CPP ${BASE} bool >> ${FILENAME}
	Footer >> ${FILENAME}

}

SetMapElements_BASE_CPP map
SetMapElements_BASE_CPP unordered_map
