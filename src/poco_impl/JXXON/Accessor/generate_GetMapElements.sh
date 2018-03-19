#!/bin/bash

function GetMapElements_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetMapElements_INCLUDED
#define JXXON_Accessor_GetMapElements_INCLUDED

namespace JXXON {
namespace Accessor {

template<typename T, template<typename...> class Base>
GetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::GetMapElements(const Json& json) : json(json)
{
}

template<typename T, template<typename...> class Base>
void GetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()(Json::MapBase<T, Base>& map) const
{
	map.clear();
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getObject()) {
				map.emplace(i.first, i.second.isEmpty() ? T() : i.second.convert<T>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_GetMapElements_INCLUDED
EOF
}

GetMapElements_TCC > GetMapElements.tcc

function GetMapElements_shared_ptr_TCC {
cat << EOF
//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetMapElements_shared_ptr_INCLUDED
#define JXXON_Accessor_GetMapElements_shared_ptr_INCLUDED

namespace JXXON {
namespace Accessor {

template<typename T, template<typename...> class Base>
GetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::GetMapElements(const Json& json) : json(json)
{
}

template<typename T, template<typename...> class Base>
void GetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()(Json::MapBase<T, Base>& map) const
{
	map.clear();
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getObject()) {
				map.emplace(i.first, i.second.isEmpty() ? T() : std::make_shared<typename T::element_type>(i.second.convert<typename T::element_type>()));
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_GetMapElements_shared_ptr_INCLUDED
EOF
}

GetMapElements_shared_ptr_TCC > GetMapElements_shared_ptr.tcc

function GetMapElements_SPECIALIZATION {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g"
template<>
void GetMapElements<{{ELEMENT_TYPE}}, Polymorphic::{{BASE}}>::operator()(Json::MapBase<{{ELEMENT_TYPE}}, Polymorphic::{{BASE}}>& map) const
{
	map.clear();
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getObject()) {
				map.emplace(i.first, i.second.isEmpty() ? {{ELEMENT_TYPE}}() : i.second.extract<{{ELEMENT_TYPE}}>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

EOF
}

function GetMapElements_shared_ptr_SPECIALIZATION {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g"
template<>
void GetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>, Polymorphic::{{BASE}}>::operator()(Json::MapBase<std::shared_ptr<{{ELEMENT_TYPE}}>, Polymorphic::{{BASE}}>& map) const
{
	map.clear();
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getObject()) {
				map.emplace(i.first, i.second.isEmpty() ? nullptr : std::make_shared<{{ELEMENT_TYPE}}>(i.second.extract<{{ELEMENT_TYPE}}>()));
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

function GetMapElements_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g"
template GetMapElements<{{ELEMENT_TYPE}}, Polymorphic::{{BASE}}>::GetMapElements(const Json& json);
template void GetMapElements<{{ELEMENT_TYPE}}, Polymorphic::{{BASE}}>::operator()(Json::MapBase<{{ELEMENT_TYPE}}, Polymorphic::{{BASE}}>& map) const;
EOF
}

function GetMapElements_shared_ptr_CPP {
cat << EOF | sed "s/{{BASE}}/$1/g" | sed "s/{{ELEMENT_TYPE}}/$2/g"
template GetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>, Polymorphic::{{BASE}}>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<{{ELEMENT_TYPE}}>, Polymorphic::{{BASE}}>::operator()(Json::MapBase<std::shared_ptr<{{ELEMENT_TYPE}}>, Polymorphic::{{BASE}}>& map) const;
EOF
}

function Footer {
cat << EOF

} // namespace Accessor
} // namespace JXXON
EOF
}


function GetMapElements_BASE_CPP {

	BASE=$1
	    
	FILENAME=GetMapElements_${BASE}_string.cpp
	Header GetMapElements.tcc ${BASE} > ${FILENAME}
	GetMapElements_SPECIALIZATION ${BASE} std::string >> ${FILENAME}
	GetMapElements_CPP ${BASE} std::string >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_shared_ptr_string.cpp
	Header GetMapElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	GetMapElements_shared_ptr_SPECIALIZATION ${BASE} std::string >> ${FILENAME}
	GetMapElements_shared_ptr_CPP ${BASE} std::string >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_int.cpp
	Header GetMapElements.tcc ${BASE} > ${FILENAME}
	GetMapElements_CPP ${BASE} int >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
	GetMapElements_CPP ${BASE} std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
	GetMapElements_CPP ${BASE} std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_shared_ptr_int.cpp
	Header GetMapElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	GetMapElements_shared_ptr_CPP ${BASE} int >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_INT64_T != _SIZEOF_INT
EOF
	GetMapElements_shared_ptr_CPP ${BASE} std::int64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
EOF
	GetMapElements_shared_ptr_CPP ${BASE} std::intmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_unsigned_int.cpp
	Header GetMapElements.tcc ${BASE} > ${FILENAME}
	GetMapElements_CPP ${BASE} 'unsigned int' >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
	GetMapElements_CPP ${BASE} std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
	GetMapElements_CPP ${BASE} std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_shared_ptr_unsigned_int.cpp
	Header GetMapElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	GetMapElements_shared_ptr_CPP ${BASE} 'unsigned int' >> ${FILENAME}
cat << EOF >> ${FILENAME}

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
EOF
	GetMapElements_shared_ptr_CPP ${BASE} std::uint64_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
EOF
	GetMapElements_shared_ptr_CPP ${BASE} std::uintmax_t >> ${FILENAME}
cat << EOF >> ${FILENAME}
#endif
EOF
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_float.cpp
	Header GetMapElements.tcc ${BASE} > ${FILENAME}
	GetMapElements_CPP ${BASE} float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	GetMapElements_CPP ${BASE} double >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_shared_ptr_float.cpp
	Header GetMapElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	GetMapElements_shared_ptr_CPP ${BASE} float >> ${FILENAME}
cat << EOF >> ${FILENAME}

EOF
	GetMapElements_shared_ptr_CPP ${BASE} double >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_bool.cpp
	Header GetMapElements.tcc ${BASE} > ${FILENAME}
	GetMapElements_SPECIALIZATION ${BASE} bool >> ${FILENAME}
	GetMapElements_CPP ${BASE} bool >> ${FILENAME}
	Footer >> ${FILENAME}


	FILENAME=GetMapElements_${BASE}_shared_ptr_bool.cpp
	Header GetMapElements_shared_ptr.tcc ${BASE} > ${FILENAME}
	GetMapElements_shared_ptr_SPECIALIZATION ${BASE} bool >> ${FILENAME}
	GetMapElements_shared_ptr_CPP ${BASE} bool >> ${FILENAME}
	Footer >> ${FILENAME}

}

GetMapElements_BASE_CPP Map
GetMapElements_BASE_CPP UnorderedMap
