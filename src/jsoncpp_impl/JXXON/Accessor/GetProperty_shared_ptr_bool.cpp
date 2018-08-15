//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetProperty_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetProperty<std::shared_ptr<bool>>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::shared_ptr<bool> GetProperty<std::shared_ptr<bool>>::operator()() const
{
	return getChild<std::shared_ptr<bool>>(json.pimpl->value, name, [](const ::Json::Value& value) { return value.asBool(); });
}

template GetProperty<std::shared_ptr<bool>>::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<bool> GetProperty<std::shared_ptr<bool>>::operator()() const;

}} // namespace JXXON::Accessor
