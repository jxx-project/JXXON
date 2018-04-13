//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
void GetArrayElements<std::shared_ptr<std::string>>::operator()(Json::ArrayType<std::shared_ptr<std::string>>& array) const
{
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getArray()) {
				array.addElement(i.isEmpty() ? nullptr : std::make_shared<std::string>(i.extract<std::string>()));
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetArrayElements<std::shared_ptr<std::string>>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::string>>::operator()(Json::ArrayType<std::shared_ptr<std::string>>& array) const;

}} // namespace JXXON::Accessor
