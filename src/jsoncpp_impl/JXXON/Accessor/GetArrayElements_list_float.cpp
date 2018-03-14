//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetArrayElements.hpp"
#include <cstdint>
#include <list>

namespace JXXON {
namespace Accessor {

template<>
GetArrayElements<float, std::list>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<float, std::list>::operator()(Json::ArrayBase<float, std::list>& array) const
{
	populateArray<float, std::list>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asFloat();});
}

template GetArrayElements<float, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<float, std::list>::operator()(Json::ArrayBase<float, std::list>& array) const;

template<>
GetArrayElements<double, std::list>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<double, std::list>::operator()(Json::ArrayBase<double, std::list>& array) const
{
	populateArray<double, std::list>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asDouble();});
}

template GetArrayElements<double, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<double, std::list>::operator()(Json::ArrayBase<double, std::list>& array) const;

} // namespace Accessor
} // namespace JXXON
