//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetProperty_shared_ptr.hpp"

namespace JXXON {
namespace Accessor {

template<>
GetProperty< std::shared_ptr<float> >::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::shared_ptr<float> GetProperty< std::shared_ptr<float> >::operator()() const
{
	return getChild< std::shared_ptr<float> >(json.pimpl->value, name, [](const ::Json::Value& value){return value.asFloat();});
}

template GetProperty< std::shared_ptr<float> >::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<float> GetProperty< std::shared_ptr<float> >::operator()() const;

template<>
GetProperty< std::shared_ptr<double> >::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::shared_ptr<double> GetProperty< std::shared_ptr<double> >::operator()() const
{
	return getChild< std::shared_ptr<double> >(json.pimpl->value, name, [](const ::Json::Value& value){return value.asDouble();});
}

template GetProperty< std::shared_ptr<double> >::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<double> GetProperty< std::shared_ptr<double> >::operator()() const;

} // namespace Accessor
} // namespace JXXON
