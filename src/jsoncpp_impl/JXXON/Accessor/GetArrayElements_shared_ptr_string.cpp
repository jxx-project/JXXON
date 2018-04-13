//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetArrayElements<std::shared_ptr<std::string>>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::string>>::operator()(Json::ArrayType<std::shared_ptr<std::string>>& array) const
{
	populateArray<std::shared_ptr<std::string>>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asString();});
}

template GetArrayElements<std::shared_ptr<std::string>>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::string>>::operator()(Json::ArrayType<std::shared_ptr<std::string>>& array) const;

}} // namespace JXXON::Accessor
