//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetArrayElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
void GetArrayElements<std::shared_ptr<bool>>::operator()(Json::ArrayType<std::shared_ptr<bool>>& array) const
{
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getArray()) {
				array.addElement(i.isEmpty() ? nullptr : std::make_shared<bool>(i.extract<bool>()));
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetArrayElements<std::shared_ptr<bool>>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<bool>>::operator()(Json::ArrayType<std::shared_ptr<bool>>& array) const;

}} // namespace JXXON::Accessor
