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
GetArrayElements<std::string, std::list>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::string, std::list>::operator()(Json::ArrayBase<std::string, std::list>& array) const
{
	populateArray<std::string, std::list>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asString();});
}

template GetArrayElements<std::string, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<std::string, std::list>::operator()(Json::ArrayBase<std::string, std::list>& array) const;

} // namespace Accessor
} // namespace JXXON
