//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetProperty.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetProperty<float>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
float GetProperty<float>::operator()() const
{
	return getChild<float>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asFloat();});
}

template GetProperty<float>::GetProperty(const Json& json, const std::string& name);
template float GetProperty<float>::operator()() const;

template<>
GetProperty<double>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
double GetProperty<double>::operator()() const
{
	return getChild<double>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asDouble();});
}

template GetProperty<double>::GetProperty(const Json& json, const std::string& name);
template double GetProperty<double>::operator()() const;

}} // namespace JXXON::Accessor
