//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetProperty.tcc"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template<>
GetProperty<std::string>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::string GetProperty<std::string>::operator()() const
{
	return getChild<std::string>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asString();});
}

template GetProperty<std::string>::GetProperty(const Json& json, const std::string& name);
template std::string GetProperty<std::string>::operator()() const;

} // namespace Accessor
} // namespace JXXON
