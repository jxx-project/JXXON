//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_SetArrayElements_shared_ptr_INCLUDED
#define JXXON_Accessor_SetArrayElements_shared_ptr_INCLUDED

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
	for (auto i = array.begin(); i != array.end(); ++i) {
		json.pimpl->value.append(*i ? ::Json::Value((typename T::element_type)**i) : ::Json::Value::null);
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_SetArrayElements_shared_ptr_INCLUDED
