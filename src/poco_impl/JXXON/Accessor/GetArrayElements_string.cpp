//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
void GetArrayElements<std::string>::operator()(Json::ArrayType<std::string>& array) const
{
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getArray()) {
				array.addElement(i.isEmpty() ? std::string() : i.extract<std::string>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetArrayElements<std::string>::GetArrayElements(const Json& json);
template void GetArrayElements<std::string>::operator()(Json::ArrayType<std::string>& array) const;

}} // namespace JXXON::Accessor
