//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
void GetMapElements<bool>::operator()(Json::MapType<bool>& map) const
{
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getObject()) {
				map.addElement(i.first, i.second.isEmpty() ? bool() : i.second.extract<bool>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetMapElements<bool>::GetMapElements(const Json& json);
template void GetMapElements<bool>::operator()(Json::MapType<bool>& map) const;

}} // namespace JXXON::Accessor
