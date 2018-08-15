//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetProperty.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
bool GetProperty<bool>::operator()() const
{
	if (json.pimpl) {
		try {
			auto child = json.pimpl->getObject().get(name);
			if (!child.isEmpty()) {
				return child.extract<bool>();
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
	return bool();
}

template GetProperty<bool>::GetProperty(const Json& json, const std::string& name);
template bool GetProperty<bool>::operator()() const;

}} // namespace JXXON::Accessor
