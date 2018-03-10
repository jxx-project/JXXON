//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetArrayElements_shared_ptr.hpp"
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
	populateArray<std::shared_ptr<float>, std::list>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asFloat();});
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
	populateArray<std::shared_ptr<double>, std::list>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asDouble();});
}

template GetArrayElements<std::shared_ptr<double>, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<double>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<double>, std::list>& array) const;

} // namespace Accessor
} // namespace JXXON
