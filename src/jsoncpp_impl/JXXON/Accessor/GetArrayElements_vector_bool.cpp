//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetArrayElements.hpp"
#include <vector>

namespace JXXON {
namespace Accessor {

template<>
GetArrayElements<bool, std::vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<bool, std::vector>::operator()(Json::ArrayBase<bool, std::vector>& array) const
{
	populateArray<bool, std::vector>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asBool();});
}

template GetArrayElements<bool, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<bool, std::vector>::operator()(Json::ArrayBase<bool, std::vector>& array) const;

} // namespace Accessor
} // namespace JXXON
