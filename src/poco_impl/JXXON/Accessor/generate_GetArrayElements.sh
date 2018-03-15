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

namespace JXXON {
namespace Accessor {

template<typename T, template<typename...> class Base>
GetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::GetArrayElements(const Json& json) : json(json)
{
}

template<typename T, template<typename...> class Base>
void GetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()(Json::ArrayBase<T, Base>& array) const
{
	array.clear();
	if (json.pimpl) {
		auto impl = json.pimpl->getArray();
		try {
			for (int i = 0; i != impl->size(); ++i) {
				array.emplace_back(impl->isNull(i) ? T() : impl->get(i).convert<T>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

} // namespace Accessor
} // namespace JXXON

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

namespace JXXON {
namespace Accessor {

template<typename T, template<typename...> class Base>
GetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::GetArrayElements(const Json& json) : json(json)
{
}

template<typename T, template<typename...> class Base>
void GetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()(Json::ArrayBase<T, Base>& array) const
{
	array.clear();
	if (json.pimpl) {
		auto impl = json.pimpl->getArray();
		try {
			for (int i = 0; i != impl->size(); ++i) {
				array.emplace_back(impl->isNull(i) ? nullptr : std::make_shared<typename T::element_type>(impl->get(i).convert<typename T::element_type>()));
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED
EOF
}

GetArrayElements_shared_ptr_TCC > GetArrayElements_shared_ptr.tcc

function GetArrayElements_SPECIALIZATION {
# C++11 is not required to provide std::vector<bool>::emplace_back
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g" | sed "s/{{APPEND}}/$([[ $1 = vector && $2 = bool ]] && echo push_back || echo emplace_back)/g"
template<>
void GetArrayElements<{{ELEMENT_TYPE}}, std::{{BASE}}>::operator()(Json::ArrayBase<{{ELEMENT_TYPE}}, std::{{BASE}}>& array) const
{
	array.clear();
	if (json.pimpl) {
		auto impl = json.pimpl->getArray();
		try {
			for (int i = 0; i != impl->size(); ++i) {
				array.{{APPEND}}(impl->isNull(i) ? {{ELEMENT_TYPE}}() : impl->get(i).extract<{{ELEMENT_TYPE}}>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

EOF
}

function GetArrayElements_shared_ptr_SPECIALIZATION {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g"
template<>
void GetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>::operator()(Json::ArrayBase<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>& array) const
{
	array.clear();
	if (json.pimpl) {
		auto impl = json.pimpl->getArray();
		try {
			for (int i = 0; i != impl->size(); ++i) {
				array.emplace_back(impl->isNull(i) ? nullptr : std::make_shared<{{ELEMENT_TYPE}}>(impl->get(i).extract<{{ELEMENT_TYPE}}>()));
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

EOF
}

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

function GetArrayElements_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g"
template GetArrayElements<{{ELEMENT_TYPE}}, std::{{BASE}}>::GetArrayElements(const Json& json);
template void GetArrayElements<{{ELEMENT_TYPE}}, std::{{BASE}}>::operator()(Json::ArrayBase<{{ELEMENT_TYPE}}, std::{{BASE}}>& array) const;
EOF
}

function GetArrayElements_shared_ptr_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g"
template GetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>::operator()(Json::ArrayBase<std::shared_ptr<{{ELEMENT_TYPE}}>, std::{{BASE}}>& array) const;
EOF
}

function Footer {
cat << EOF

} // namespace Accessor
} // namespace JXXON
EOF
}


function GetArrayElements_BASE_CPP {

	BASE=$1
	    
	FILENAME=GetArrayElements_${BASE}_string.cpp
	Header GetArrayElements.tcc ${BASE} > ${FILENAME}
	GetArrayElements_SPECIALIZATION ${BASE} std::string >> ${FILENAME}
	GetArrayElements_CPP ${BASE} std::string >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_shared_ptr_string.cpp
	Header GetArrayElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	GetArrayElements_shared_ptr_SPECIALIZATION ${BASE} std::string >> ${FILENAME}
	GetArrayElements_shared_ptr_CPP ${BASE} std::string >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_int.cpp
	Header GetArrayElements.tcc ${BASE} > ${FILENAME}
	GetArrayElements_CPP ${BASE} int >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
	GetArrayElements_CPP ${BASE} std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
	GetArrayElements_CPP ${BASE} std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_shared_ptr_int.cpp
	Header GetArrayElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	GetArrayElements_shared_ptr_CPP ${BASE} int >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
	GetArrayElements_shared_ptr_CPP ${BASE} std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
	GetArrayElements_shared_ptr_CPP ${BASE} std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_unsigned_int.cpp
	Header GetArrayElements.tcc ${BASE} > ${FILENAME}
	GetArrayElements_CPP ${BASE} 'unsigned int' >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
	GetArrayElements_CPP ${BASE} std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
	GetArrayElements_CPP ${BASE} std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_shared_ptr_unsigned_int.cpp
	Header GetArrayElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	GetArrayElements_shared_ptr_CPP ${BASE} 'unsigned int' >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
	GetArrayElements_shared_ptr_CPP ${BASE} std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
	GetArrayElements_shared_ptr_CPP ${BASE} std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_float.cpp
	Header GetArrayElements.tcc ${BASE} > ${FILENAME}
	GetArrayElements_CPP ${BASE} float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	GetArrayElements_CPP ${BASE} double >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_shared_ptr_float.cpp
	Header GetArrayElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	GetArrayElements_shared_ptr_CPP ${BASE} float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	GetArrayElements_shared_ptr_CPP ${BASE} double >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_bool.cpp
	Header GetArrayElements.tcc ${BASE} > ${FILENAME}
	GetArrayElements_SPECIALIZATION ${BASE} bool >> ${FILENAME}
	GetArrayElements_CPP ${BASE} bool >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetArrayElements_${BASE}_shared_ptr_bool.cpp
	Header GetArrayElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	GetArrayElements_shared_ptr_SPECIALIZATION ${BASE} bool >> ${FILENAME}
	GetArrayElements_shared_ptr_CPP ${BASE} bool >> ${FILENAME}
	Footer >> ${FILENAME}

}

GetArrayElements_BASE_CPP vector
GetArrayElements_BASE_CPP list
