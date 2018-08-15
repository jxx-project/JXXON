//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_SetArrayElements_shared_ptr_INCLUDED
#define JXXON_Accessor_SetArrayElements_shared_ptr_INCLUDED

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"

namespace JXXON { namespace Accessor {

template<typename T>
SetArrayElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::SetArrayElements(Json& json) :
	json(json)
{
	json.setTypeArray();
}

template<typename T>
void SetArrayElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()(const Json::ArrayType<T>& array)
{
	array.forEach([&](const T& element) { json.pimpl->value.append(element ? ::Json::Value(*element) : ::Json::Value::null); });
}

}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_SetArrayElements_shared_ptr_INCLUDED
