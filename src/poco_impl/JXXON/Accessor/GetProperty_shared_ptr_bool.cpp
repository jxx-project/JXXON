//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetProperty_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
std::shared_ptr<bool> GetProperty<std::shared_ptr<bool>>::operator()() const
{
	if (json.pimpl) {
		try {
			auto child = json.pimpl->getObject().get(name);
			if (!child.isEmpty()) {
				return std::make_shared<bool>(child.extract<bool>());
			}
		} catch (Poco::Exception& e) {
			throw Error(e.message());
		}
	}
	return nullptr;
}

template GetProperty<std::shared_ptr<bool>>::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<bool> GetProperty<std::shared_ptr<bool>>::operator()() const;

}} // namespace JXXON::Accessor
