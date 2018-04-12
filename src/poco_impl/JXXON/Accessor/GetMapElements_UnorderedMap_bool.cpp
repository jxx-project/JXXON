//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/UnorderedMap.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
void GetMapElements<bool, Base::UnorderedMap>::operator()(Base::UnorderedMap<bool>& map) const
{
	map.clear();
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

template GetMapElements<bool, Base::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<bool, Base::UnorderedMap>::operator()(Base::UnorderedMap<bool>& map) const;

}} // namespace JXXON::Accessor
