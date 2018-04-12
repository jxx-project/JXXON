//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/List.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetArrayElements<std::shared_ptr<bool>, Base::List>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<bool>, Base::List>::operator()(Base::List<std::shared_ptr<bool>>& array) const
{
	populateArray<std::shared_ptr<bool>, Base::List>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asBool();});
}

template GetArrayElements<std::shared_ptr<bool>, Base::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<bool>, Base::List>::operator()(Base::List<std::shared_ptr<bool>>& array) const;

}} // namespace JXXON::Accessor
