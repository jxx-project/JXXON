//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetMapElements_shared_ptr.hpp"
#include <cstdint>
#include <map>

namespace JXXON {
namespace Accessor {

template<>
void GetMapElements<std::shared_ptr<bool>, std::map>::operator()(Json::MapBase<std::shared_ptr<bool>, std::map>& map) const
{
	map.clear();
	if (json.pimpl) {
		auto impl = json.pimpl->getObject();
		try {
			for (auto i = impl->begin(); i != impl->end(); ++i) {
				map.emplace(i->first, i->second.isEmpty() ? nullptr : std::make_shared<bool>(i->second.extract<bool>()));
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetMapElements<std::shared_ptr<bool>, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<bool>, std::map>::operator()(Json::MapBase<std::shared_ptr<bool>, std::map>& map) const;

} // namespace Accessor
} // namespace JXXON
