#!/bin/bash

function SetMapElements_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_SetMapElements_INCLUDED
#define JXXON_Accessor_SetMapElements_INCLUDED

namespace JXXON {
namespace Accessor {

template<typename T, template<typename...> class Base>
SetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::SetMapElements(Json& json) : json(json)
{
	json.setTypeObject();
}

template<typename T, template<typename...> class Base>
void SetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()(const Base<std::string, T>& map)
{
	for (const auto& i : map) {
		json.pimpl->value[i.first] = i.second;
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_SetMapElements_INCLUDED
EOF
}

SetMapElements_TCC > SetMapElements.tcc

function SetMapElements_shared_ptr_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_SetMapElements_shared_ptr_INCLUDED
#define JXXON_Accessor_SetMapElements_shared_ptr_INCLUDED

namespace JXXON {
namespace Accessor {

template<typename T, template<typename...> class Base>
SetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::SetMapElements(Json& json) : json(json)
{
	json.setTypeObject();
}

template<typename T, template<typename...> class Base>
void SetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()(const Base<std::string, T>& map)
{
	for (const auto& i : map) {
		json.pimpl->value[i.first] = i.second ? *i.second : ::Json::Value::null;
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_SetMapElements_shared_ptr_INCLUDED
EOF
}

SetMapElements_shared_ptr_TCC > SetMapElements_shared_ptr.tcc

function Header {
cat << EOF | sed "s/{{INCLUDE}}/$1/g"| sed "s/{{BASE}}/$2/g"
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/{{INCLUDE}}"
#include <cstdint>
#include <Polymorphic/{{BASE}}.h>

namespace JXXON {
namespace Accessor {

EOF
}

function SetMapElements_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g"
template SetMapElements<{{ELEMENT_TYPE}}, Polymorphic::{{BASE}}>::SetMapElements(Json& json);
template void SetMapElements<{{ELEMENT_TYPE}}, Polymorphic::{{BASE}}>::operator()(const Polymorphic::{{BASE}}<std::string, {{ELEMENT_TYPE}}>& map);
EOF
}

function SetMapElements_shared_ptr_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g"
template SetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>, Polymorphic::{{BASE}}>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>, Polymorphic::{{BASE}}>::operator()(const Polymorphic::{{BASE}}< std::string, std::shared_ptr<{{ELEMENT_TYPE}}> >& map);
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
	Header SetMapElements.tcc ${BASE} > ${FILENAME}
	SetMapElements_CPP ${BASE} std::string >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=SetMapElements_${BASE}_shared_ptr_string.cpp
	Header SetMapElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	SetMapElements_shared_ptr_CPP ${BASE} std::string >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=SetMapElements_${BASE}_int.cpp
	Header SetMapElements.tcc ${BASE} > ${FILENAME}
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
	Header SetMapElements_shared_ptr.tcc ${BASE} > ${FILENAME}
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
	Header SetMapElements.tcc ${BASE} > ${FILENAME}
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
	Header SetMapElements_shared_ptr.tcc ${BASE} > ${FILENAME}
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
	Header SetMapElements.tcc ${BASE} > ${FILENAME}
	SetMapElements_CPP ${BASE} float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	SetMapElements_CPP ${BASE} double >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=SetMapElements_${BASE}_shared_ptr_float.cpp
	Header SetMapElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	SetMapElements_shared_ptr_CPP ${BASE} float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	SetMapElements_shared_ptr_CPP ${BASE} double >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=SetMapElements_${BASE}_bool.cpp
	Header SetMapElements.tcc ${BASE} > ${FILENAME}
	SetMapElements_CPP ${BASE} bool >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=SetMapElements_${BASE}_shared_ptr_bool.cpp
	Header SetMapElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	SetMapElements_shared_ptr_CPP ${BASE} bool >> ${FILENAME}
	Footer >> ${FILENAME}

}

SetMapElements_BASE_CPP Map
SetMapElements_BASE_CPP UnorderedMap
