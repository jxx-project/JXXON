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
#include <Polymorphic/Vector.h>

namespace JXXON { namespace Accessor {

template<>
void GetArrayElements<std::string, Polymorphic::Vector>::operator()(Polymorphic::Vector<std::string>& array) const
{
	array.clear();
	if (json.pimpl) {
		try {
			for (const auto& i : json.pimpl->getArray()) {
				array.emplace_back(i.isEmpty() ? std::string() : i.extract<std::string>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
}

template GetArrayElements<std::string, Polymorphic::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::string, Polymorphic::Vector>::operator()(Polymorphic::Vector<std::string>& array) const;

}} // namespace JXXON::Accessor
