//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_GetArrayElements_INCLUDED
#define JXXON_Accessor_GetArrayElements_INCLUDED

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"

namespace JXXON { namespace Accessor {

template<typename T>
GetArrayElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::GetArrayElements(const Json& json) :
	json(json)
{
}

template<typename T>
void GetArrayElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()(Json::ArrayType<T>& array) const
{
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getArray()) {
				array.addElement(i.isEmpty() ? T() : i.convert<T>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_GetArrayElements_INCLUDED
