//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_SetArrayElements_shared_ptr_INCLUDED
#define JXXON_Accessor_SetArrayElements_shared_ptr_INCLUDED

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"

namespace JXXON {
namespace Accessor {

template<typename T, template<typename...> class Base>
SetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::SetArrayElements(Json& json) : json(json)
{
	json.setTypeArray();
}

template<typename T, template<typename...> class Base>
void SetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()(const Json::ArrayBase<T, Base>& array)
{
	auto impl = json.pimpl->getArray();
	for (typename Json::ArrayBase<T, Base>::const_iterator i = array.begin(); i != array.end(); ++i) {
		impl->add(*i ? Poco::Dynamic::Var(**i) : Poco::Dynamic::Var());
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_SetArrayElements_shared_ptr_INCLUDED
