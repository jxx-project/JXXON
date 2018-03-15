//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include "JXXON/Accessor/GetProperty.tcc"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template<>
std::string GetProperty<std::string>::operator()() const
{
	if (json.pimpl) {
		try {
			auto child = json.pimpl->getObject()->get(name);
			if (!child.isEmpty()) {
				return child.extract<std::string>();
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
	return std::string();
}

template GetProperty<std::string>::GetProperty(const Json& json, const std::string& name);
template std::string GetProperty<std::string>::operator()() const;

} // namespace Accessor
} // namespace JXXON
