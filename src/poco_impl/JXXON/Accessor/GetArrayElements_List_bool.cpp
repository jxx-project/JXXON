//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>
#include <Polymorphic/List.h>

namespace JXXON { namespace Accessor {

template<>
void GetArrayElements<bool, Polymorphic::List>::operator()(Polymorphic::List<bool>& array) const
{
	array.clear();
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getArray()) {
				array.emplace_back(i.isEmpty() ? bool() : i.extract<bool>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetArrayElements<bool, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<bool, Polymorphic::List>::operator()(Polymorphic::List<bool>& array) const;

}} // namespace JXXON::Accessor
