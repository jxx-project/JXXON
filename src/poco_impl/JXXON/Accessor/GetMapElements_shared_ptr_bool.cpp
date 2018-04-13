//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
void GetMapElements<std::shared_ptr<bool>>::operator()(Json::MapType<std::shared_ptr<bool>>& map) const
{
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getObject()) {
				map.addElement(i.first, i.second.isEmpty() ? nullptr : std::make_shared<bool>(i.second.extract<bool>()));
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetMapElements<std::shared_ptr<bool>>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<bool>>::operator()(Json::MapType<std::shared_ptr<bool>>& map) const;

}} // namespace JXXON::Accessor
