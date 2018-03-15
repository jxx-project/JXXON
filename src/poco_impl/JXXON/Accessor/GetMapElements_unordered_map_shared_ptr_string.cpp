//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>
#include <unordered_map>

namespace JXXON {
namespace Accessor {

template<>
void GetMapElements<std::shared_ptr<std::string>, std::unordered_map>::operator()(Json::MapBase<std::shared_ptr<std::string>, std::unordered_map>& map) const
{
	map.clear();
	if (json.pimpl) {
		auto impl = json.pimpl->getObject();
		try {
			for (auto i = impl->begin(); i != impl->end(); ++i) {
				map.emplace(i->first, i->second.isEmpty() ? nullptr : std::make_shared<std::string>(i->second.extract<std::string>()));
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetMapElements<std::shared_ptr<std::string>, std::unordered_map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::string>, std::unordered_map>::operator()(Json::MapBase<std::shared_ptr<std::string>, std::unordered_map>& map) const;

} // namespace Accessor
} // namespace JXXON
