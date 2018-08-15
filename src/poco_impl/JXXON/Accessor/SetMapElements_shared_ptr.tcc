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
	map.forEach([&](const std::string& key, const T& value) {
		json.pimpl->getObject().set(key, value ? Poco::Dynamic::Var(*value) : Poco::Dynamic::Var());
	});
}

}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_SetMapElements_shared_ptr_INCLUDED
