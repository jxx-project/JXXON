//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetArrayElements.hpp"
#include <list>

namespace JXXON {
namespace Accessor {

template<>
void GetArrayElements<std::string, std::list>::operator()(Json::ArrayBase<std::string, std::list>& array) const
{
	array.clear();
	if (json.pimpl) {
		auto impl = json.pimpl->getArray();
		try {
			for (int i = 0; i != impl->size(); ++i) {
				array.emplace_back(impl->isNull(i) ? std::string() : impl->get(i).extract<std::string>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetArrayElements<std::string, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<std::string, std::list>::operator()(Json::ArrayBase<std::string, std::list>& array) const;

} // namespace Accessor
} // namespace JXXON
