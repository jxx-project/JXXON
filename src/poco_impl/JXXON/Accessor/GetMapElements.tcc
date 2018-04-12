//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetMapElements_INCLUDED
#define JXXON_Accessor_GetMapElements_INCLUDED

namespace JXXON { namespace Accessor {

template<typename T, template<typename...> class Base>
GetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::GetMapElements(const Json& json) : json(json)
{
}

template<typename T, template<typename...> class Base>
void GetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>::operator()(Base<T>& map) const
{
	map.clear();
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getObject()) {
				map.emplace(i.first, i.second.isEmpty() ? T() : i.second.convert<T>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_GetMapElements_INCLUDED
