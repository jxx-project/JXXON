//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetArrayElements.hpp"
#include <cstdint>
#include <vector>

namespace JXXON {
namespace Accessor {

template<>
GetArrayElements<std::string, std::vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::string, std::vector>::operator()(Json::ArrayBase<std::string, std::vector>& array) const
{
	populateArray<std::string, std::vector>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asString();});
}

template GetArrayElements<std::string, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::string, std::vector>::operator()(Json::ArrayBase<std::string, std::vector>& array) const;

} // namespace Accessor
} // namespace JXXON
