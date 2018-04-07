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

namespace JXXON { namespace Accessor {

template<>
GetArrayElements<float, Polymorphic::List>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<float, Polymorphic::List>::operator()(Polymorphic::List<float>& array) const
{
	populateArray<float, Polymorphic::List>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asFloat();});
}

template GetArrayElements<float, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<float, Polymorphic::List>::operator()(Polymorphic::List<float>& array) const;

template<>
GetArrayElements<double, Polymorphic::List>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<double, Polymorphic::List>::operator()(Polymorphic::List<double>& array) const
{
	populateArray<double, Polymorphic::List>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asDouble();});
}

template GetArrayElements<double, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<double, Polymorphic::List>::operator()(Polymorphic::List<double>& array) const;

}} // namespace JXXON::Accessor
