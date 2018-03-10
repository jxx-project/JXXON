//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetArrayElements.hpp"
#include <vector>

namespace JXXON {
namespace Accessor {

template<>
void GetArrayElements<bool, std::vector>::operator()(Json::ArrayBase<bool, std::vector>& array) const
{
	array.clear();
	if (json.pimpl) {
		auto impl = json.pimpl->getArray();
		try {
			for (int i = 0; i != impl->size(); ++i) {
				array.emplace_back(impl->isNull(i) ? bool() : impl->get(i).extract<bool>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetArrayElements<bool, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<bool, std::vector>::operator()(Json::ArrayBase<bool, std::vector>& array) const;

} // namespace Accessor
} // namespace JXXON
