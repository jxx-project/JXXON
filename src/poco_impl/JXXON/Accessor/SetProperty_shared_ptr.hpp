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
