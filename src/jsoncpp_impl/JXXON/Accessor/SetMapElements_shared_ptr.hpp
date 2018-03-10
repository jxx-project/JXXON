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
