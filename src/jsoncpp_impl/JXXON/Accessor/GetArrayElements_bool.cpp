//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetArrayElements<bool>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<bool>::operator()(Json::ArrayType<bool>& array) const
{
	populateArray<bool>(array, json.pimpl->value, [](const ::Json::Value& value) { return value.asBool(); });
}

template GetArrayElements<bool>::GetArrayElements(const Json& json);
template void GetArrayElements<bool>::operator()(Json::ArrayType<bool>& array) const;

}} // namespace JXXON::Accessor
