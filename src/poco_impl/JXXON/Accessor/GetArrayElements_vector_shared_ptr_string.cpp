//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetArrayElements_shared_ptr.hpp"
#include <cstdint>
#include <vector>

namespace JXXON {
namespace Accessor {

template<>
void GetArrayElements<std::shared_ptr<std::string>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<std::string>, std::vector>& array) const
{
	array.clear();
	if (json.pimpl) {
		auto impl = json.pimpl->getArray();
		try {
			for (int i = 0; i != impl->size(); ++i) {
				array.emplace_back(impl->isNull(i) ? nullptr : std::make_shared<std::string>(impl->get(i).extract<std::string>()));
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetArrayElements<std::shared_ptr<std::string>, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::string>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<std::string>, std::vector>& array) const;

} // namespace Accessor
} // namespace JXXON
