//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_SetProperty_INCLUDED
#define JXXON_Accessor_SetProperty_INCLUDED

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"

namespace JXXON { namespace Accessor {

template<typename T>
SetProperty<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::
		type>::SetProperty(Json& json, const std::string& name) :
	json(json),
	name(name)
{
	json.setTypeObject();
}

template<typename T>
void SetProperty<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()(const T& value)
{
	json.pimpl->value[name] = value;
}

}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_SetProperty_INCLUDED
