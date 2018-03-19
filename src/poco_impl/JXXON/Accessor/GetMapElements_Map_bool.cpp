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
void GetMapElements<bool, Polymorphic::Map>::operator()(Json::MapBase<bool, Polymorphic::Map>& map) const
{
	map.clear();
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getObject()) {
				map.emplace(i.first, i.second.isEmpty() ? bool() : i.second.extract<bool>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetMapElements<bool, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<bool, Polymorphic::Map>::operator()(Json::MapBase<bool, Polymorphic::Map>& map) const;

} // namespace Accessor
} // namespace JXXON
