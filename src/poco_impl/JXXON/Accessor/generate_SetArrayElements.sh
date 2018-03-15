#!/bin/bash

function SetArrayElements_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_SetArrayElements_INCLUDED
#define JXXON_Accessor_SetArrayElements_INCLUDED

namespace JXXON {
namespace Accessor {

template<typename T, template<typename...> class Base>
SetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::SetArrayElements(Json& json) : json(json)
{
	json.setTypeArray();
}

template<typename T, template<typename...> class Base>
void SetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()(const Json::ArrayBase<T, Base>& array)
{
	auto impl = json.pimpl->getArray();
	for (typename Json::ArrayBase<T, Base>::const_iterator i = array.begin(); i != array.end(); ++i) {
		impl->add(Poco::Dynamic::Var(*i));
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_SetArrayElements_INCLUDED
EOF
}

SetArrayElements_TCC > SetArrayElements.tcc

function SetArrayElements_shared_ptr_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_SetArrayElements_shared_ptr_INCLUDED
#define JXXON_Accessor_SetArrayElements_shared_ptr_INCLUDED

namespace JXXON {
namespace Accessor {

template<typename T, template<typename...> class Base>
SetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::SetArrayElements(Json& json) : json(json)
{
	json.setTypeArray();
}

template<typename T, template<typename...> class Base>
void SetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()(const Json::ArrayBase<T, Base>& array)
{
	auto impl = json.pimpl->getArray();
	for (typename Json::ArrayBase<T, Base>::const_iterator i = array.begin(); i != array.end(); ++i) {
		impl->add(*i ? Poco::Dynamic::Var(**i) : Poco::Dynamic::Var());
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_SetArrayElements_shared_ptr_INCLUDED
EOF
}

SetArrayElements_shared_ptr_TCC > SetArrayElements_shared_ptr.tcc

function Header {
cat << EOF | sed "s/{{INCLUDE}}/$1/g"| sed "s/{{BASE}}/$2/g"
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include "JXXON/Accessor/{{INCLUDE}}"
#include <cstdint>
#include <{{BASE}}>

namespace JXXON {
namespace Accessor {

EOF
}

function SetArrayElements_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g"
template SetArrayElements<{{ELEMENT_TYPE}}, std::{{BASE}}>::SetArrayElements(Json& json);
template void SetArrayElements<{{ELEMENT_TYPE}}, std::{{BASE}}>::operator()(const Json::ArrayBase<{{ELEMENT_TYPE}}, std::{{BASE}}>& array);
EOF
}

function SetArrayElements_shared_ptr_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g"
template SetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>::operator()(const Json::ArrayBase<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>& array);
EOF
}

function Footer {
cat << EOF

} // namespace Accessor
} // namespace JXXON
EOF
}


function SetArrayElements_BASE_CPP {

	BASE=$1
	    
	FILENAME=SetArrayElements_${BASE}_string.cpp
	Header SetArrayElements.tcc ${BASE} > ${FILENAME}
	SetArrayElements_CPP ${BASE} std::string >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=SetArrayElements_${BASE}_shared_ptr_string.cpp
	Header SetArrayElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	SetArrayElements_shared_ptr_CPP ${BASE} std::string >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=SetArrayElements_${BASE}_int.cpp
	Header SetArrayElements.tcc ${BASE} > ${FILENAME}
	SetArrayElements_CPP ${BASE} int >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
	SetArrayElements_CPP ${BASE} std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
	SetArrayElements_CPP ${BASE} std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=SetArrayElements_${BASE}_shared_ptr_int.cpp
	Header SetArrayElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	SetArrayElements_shared_ptr_CPP ${BASE} int >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
	SetArrayElements_shared_ptr_CPP ${BASE} std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
	SetArrayElements_shared_ptr_CPP ${BASE} std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=SetArrayElements_${BASE}_unsigned_int.cpp
	Header SetArrayElements.tcc ${BASE} > ${FILENAME}
	SetArrayElements_CPP ${BASE} 'unsigned int' >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
	SetArrayElements_CPP ${BASE} std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
	SetArrayElements_CPP ${BASE} std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=SetArrayElements_${BASE}_shared_ptr_unsigned_int.cpp
	Header SetArrayElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	SetArrayElements_shared_ptr_CPP ${BASE} 'unsigned int' >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
	SetArrayElements_shared_ptr_CPP ${BASE} std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
	SetArrayElements_shared_ptr_CPP ${BASE} std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=SetArrayElements_${BASE}_float.cpp
	Header SetArrayElements.tcc ${BASE} > ${FILENAME}
	SetArrayElements_CPP ${BASE} float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	SetArrayElements_CPP ${BASE} double >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=SetArrayElements_${BASE}_shared_ptr_float.cpp
	Header SetArrayElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	SetArrayElements_shared_ptr_CPP ${BASE} float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	SetArrayElements_shared_ptr_CPP ${BASE} double >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=SetArrayElements_${BASE}_bool.cpp
	Header SetArrayElements.tcc ${BASE} > ${FILENAME}
	SetArrayElements_CPP ${BASE} bool >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=SetArrayElements_${BASE}_shared_ptr_bool.cpp
	Header SetArrayElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	SetArrayElements_shared_ptr_CPP ${BASE} bool >> ${FILENAME}
	Footer >> ${FILENAME}

}

SetArrayElements_BASE_CPP vector
SetArrayElements_BASE_CPP list
