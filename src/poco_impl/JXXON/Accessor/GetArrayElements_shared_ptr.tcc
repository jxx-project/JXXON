//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED
#define JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED

namespace JXXON {
namespace Accessor {

template<typename T, template<typename...> class Base>
GetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::GetArrayElements(const Json& json) : json(json)
{
}

template<typename T, template<typename...> class Base>
void GetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>::operator()(Json::ArrayBase<T, Base>& array) const
{
	array.clear();
	if (json.pimpl) {
		auto impl = json.pimpl->getArray();
		try {
			for (int i = 0; i != impl->size(); ++i) {
				array.emplace_back(impl->isNull(i) ? nullptr : std::make_shared<typename T::element_type>(impl->get(i).convert<typename T::element_type>()));
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED