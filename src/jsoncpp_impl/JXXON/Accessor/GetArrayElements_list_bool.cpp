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
GetArrayElements<bool, std::list>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<bool, std::list>::operator()(Json::ArrayBase<bool, std::list>& array) const
{
	populateArray<bool, std::list>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asBool();});
}

template GetArrayElements<bool, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<bool, std::list>::operator()(Json::ArrayBase<bool, std::list>& array) const;

} // namespace Accessor
} // namespace JXXON
