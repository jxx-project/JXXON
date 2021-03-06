//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetProperty_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetProperty<std::shared_ptr<std::string>>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::shared_ptr<std::string> GetProperty<std::shared_ptr<std::string>>::operator()() const
{
	return getChild<std::shared_ptr<std::string>>(json.pimpl->value, name, [](const ::Json::Value& value) { return value.asString(); });
}

template GetProperty<std::shared_ptr<std::string>>::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<std::string> GetProperty<std::shared_ptr<std::string>>::operator()() const;

}} // namespace JXXON::Accessor
