//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
void GetArrayElements<bool>::operator()(Json::ArrayType<bool>& array) const
{
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getArray()) {
				array.addElement(i.isEmpty() ? bool() : i.extract<bool>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetArrayElements<bool>::GetArrayElements(const Json& json);
template void GetArrayElements<bool>::operator()(Json::ArrayType<bool>& array) const;

}} // namespace JXXON::Accessor
