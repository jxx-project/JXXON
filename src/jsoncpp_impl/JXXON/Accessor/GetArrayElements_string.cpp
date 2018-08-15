//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetArrayElements<std::string>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::string>::operator()(Json::ArrayType<std::string>& array) const
{
	populateArray<std::string>(array, json.pimpl->value, [](const ::Json::Value& value) { return value.asString(); });
}

template GetArrayElements<std::string>::GetArrayElements(const Json& json);
template void GetArrayElements<std::string>::operator()(Json::ArrayType<std::string>& array) const;

}} // namespace JXXON::Accessor
