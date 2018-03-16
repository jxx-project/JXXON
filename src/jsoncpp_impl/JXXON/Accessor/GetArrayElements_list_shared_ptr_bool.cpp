//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements_shared_ptr.tcc"
#include <cstdint>
#include <list>

namespace JXXON {
namespace Accessor {

template<>
GetArrayElements<std::shared_ptr<bool>, std::list>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<bool>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<bool>, std::list>& array) const
{
	populateArray<std::shared_ptr<bool>, std::list>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asBool();});
}

template GetArrayElements<std::shared_ptr<bool>, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<bool>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<bool>, std::list>& array) const;

} // namespace Accessor
} // namespace JXXON
