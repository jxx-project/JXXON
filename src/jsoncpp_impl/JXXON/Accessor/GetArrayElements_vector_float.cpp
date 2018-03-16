//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>
#include <vector>

namespace JXXON {
namespace Accessor {

template<>
GetArrayElements<float, std::vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<float, std::vector>::operator()(Json::ArrayBase<float, std::vector>& array) const
{
	populateArray<float, std::vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asFloat();});
}

template GetArrayElements<float, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<float, std::vector>::operator()(Json::ArrayBase<float, std::vector>& array) const;

template<>
GetArrayElements<double, std::vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<double, std::vector>::operator()(Json::ArrayBase<double, std::vector>& array) const
{
	populateArray<double, std::vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asDouble();});
}

template GetArrayElements<double, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<double, std::vector>::operator()(Json::ArrayBase<double, std::vector>& array) const;

} // namespace Accessor
} // namespace JXXON
