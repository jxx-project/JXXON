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

namespace JXXON { namespace Accessor {

template<>
GetArrayElements<float, Polymorphic::Vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<float, Polymorphic::Vector>::operator()(Polymorphic::Vector<float>& array) const
{
	populateArray<float, Polymorphic::Vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asFloat();});
}

template GetArrayElements<float, Polymorphic::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<float, Polymorphic::Vector>::operator()(Polymorphic::Vector<float>& array) const;

template<>
GetArrayElements<double, Polymorphic::Vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<double, Polymorphic::Vector>::operator()(Polymorphic::Vector<double>& array) const
{
	populateArray<double, Polymorphic::Vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asDouble();});
}

template GetArrayElements<double, Polymorphic::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<double, Polymorphic::Vector>::operator()(Polymorphic::Vector<double>& array) const;

}} // namespace JXXON::Accessor
