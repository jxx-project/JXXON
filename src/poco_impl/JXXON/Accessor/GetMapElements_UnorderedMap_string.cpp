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
#include <Polymorphic/UnorderedMap.h>

namespace JXXON {
namespace Accessor {

template<>
void GetMapElements<std::string, Polymorphic::UnorderedMap>::operator()(Polymorphic::UnorderedMap<std::string, std::string>& map) const
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

template GetMapElements<std::string, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<std::string, Polymorphic::UnorderedMap>::operator()(Polymorphic::UnorderedMap<std::string, std::string>& map) const;

} // namespace Accessor
} // namespace JXXON
