//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetProperty_INCLUDED
#define JXXON_Accessor_GetProperty_INCLUDED

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"

namespace JXXON {
namespace Accessor {

template<typename T>
GetProperty<T,  typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<typename T>
T GetProperty<T,  typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()() const
{
	if (json.pimpl) {
		try {
			auto child = json.pimpl->getObject()->get(name);
			if (!child.isEmpty()) {
				return child.convert<T>();
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
	return T();
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_GetProperty_INCLUDED
