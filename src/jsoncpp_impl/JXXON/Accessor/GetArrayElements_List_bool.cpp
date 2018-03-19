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
#include <Polymorphic/List.h>

namespace JXXON {
namespace Accessor {

template<>
GetArrayElements<bool, Polymorphic::List>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<bool, Polymorphic::List>::operator()(Json::ArrayBase<bool, Polymorphic::List>& array) const
{
	populateArray<bool, Polymorphic::List>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asBool();});
}

template GetArrayElements<bool, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<bool, Polymorphic::List>::operator()(Json::ArrayBase<bool, Polymorphic::List>& array) const;

} // namespace Accessor
} // namespace JXXON
