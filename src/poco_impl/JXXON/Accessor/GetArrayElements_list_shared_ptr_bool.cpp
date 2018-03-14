//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetArrayElements_shared_ptr.hpp"
#include <cstdint>
#include <list>

namespace JXXON {
namespace Accessor {

template<>
void GetArrayElements<std::shared_ptr<bool>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<bool>, std::list>& array) const
{
	array.clear();
	if (json.pimpl) {
		auto impl = json.pimpl->getArray();
		try {
			for (int i = 0; i != impl->size(); ++i) {
				array.emplace_back(impl->isNull(i) ? nullptr : std::make_shared<bool>(impl->get(i).extract<bool>()));
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetArrayElements<std::shared_ptr<bool>, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<bool>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<bool>, std::list>& array) const;

} // namespace Accessor
} // namespace JXXON
