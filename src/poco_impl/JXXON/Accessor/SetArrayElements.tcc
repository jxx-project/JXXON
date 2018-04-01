//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_SetArrayElements_INCLUDED
#define JXXON_Accessor_SetArrayElements_INCLUDED

namespace JXXON {
namespace Accessor {

template<typename T, template<typename...> class Base>
SetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::SetArrayElements(Json& json) : json(json)
{
	json.setTypeArray();
}

template<typename T, template<typename...> class Base>
void SetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()(const Base<T>& array)
{
	for (const auto& i : array) {
		json.pimpl->getArray().add(Poco::Dynamic::Var(i));
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_SetArrayElements_INCLUDED
