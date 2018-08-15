//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_GetProperty_shared_ptr_INCLUDED
#define JXXON_Accessor_GetProperty_shared_ptr_INCLUDED

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"

namespace JXXON { namespace Accessor {

template<typename T>
GetProperty<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::
		type>::GetProperty(const Json& json, const std::string& name) :
	json(json),
	name(name)
{
}

template<typename T>
T GetProperty<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()() const
{
	if (json.pimpl) {
		try {
			auto child = json.pimpl->getObject().get(name);
			if (!child.isEmpty()) {
				return std::make_shared<typename T::element_type>(child.convert<typename T::element_type>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
	return nullptr;
}

}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_GetProperty_shared_ptr_INCLUDED
