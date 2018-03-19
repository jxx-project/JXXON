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
#include <Polymorphic/Vector.h>

namespace JXXON {
namespace Accessor {

template<>
GetArrayElements<bool, Polymorphic::Vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<bool, Polymorphic::Vector>::operator()(Json::ArrayBase<bool, Polymorphic::Vector>& array) const
{
	populateArray<bool, Polymorphic::Vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asBool();});
}

template GetArrayElements<bool, Polymorphic::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<bool, Polymorphic::Vector>::operator()(Json::ArrayBase<bool, Polymorphic::Vector>& array) const;

} // namespace Accessor
} // namespace JXXON
