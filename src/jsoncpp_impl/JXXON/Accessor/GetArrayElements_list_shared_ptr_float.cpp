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
GetArrayElements<std::shared_ptr<float>, std::list>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<float>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<float>, std::list>& array) const
{
	populateArray<std::shared_ptr<float>, std::list>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asFloat();});
}

template GetArrayElements<std::shared_ptr<float>, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<float>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<float>, std::list>& array) const;

template<>
GetArrayElements<std::shared_ptr<double>, std::list>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<double>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<double>, std::list>& array) const
{
	populateArray<std::shared_ptr<double>, std::list>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asDouble();});
}

template GetArrayElements<std::shared_ptr<double>, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<double>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<double>, std::list>& array) const;

} // namespace Accessor
} // namespace JXXON
