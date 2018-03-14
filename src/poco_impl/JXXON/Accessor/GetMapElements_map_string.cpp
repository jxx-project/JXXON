//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetMapElements.hpp"
#include <cstdint>
#include <map>

namespace JXXON {
namespace Accessor {

template<>
void GetMapElements<std::string, std::map>::operator()(Json::MapBase<std::string, std::map>& map) const
{
	map.clear();
	if (json.pimpl) {
		auto impl = json.pimpl->getObject();
		try {
			for (auto i = impl->begin(); i != impl->end(); ++i) {
				map.emplace(i->first, i->second.isEmpty() ? std::string() : i->second.extract<std::string>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetMapElements<std::string, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::string, std::map>::operator()(Json::MapBase<std::string, std::map>& map) const;

} // namespace Accessor
} // namespace JXXON
