//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>
#include <Polymorphic/Map.h>

namespace JXXON {
namespace Accessor {

template<>
void GetMapElements<std::string, Polymorphic::Map>::operator()(Json::MapBase<std::string, Polymorphic::Map>& map) const
{
	map.clear();
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getObject()) {
				map.emplace(i.first, i.second.isEmpty() ? std::string() : i.second.extract<std::string>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetMapElements<std::string, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::string, Polymorphic::Map>::operator()(Json::MapBase<std::string, Polymorphic::Map>& map) const;

} // namespace Accessor
} // namespace JXXON