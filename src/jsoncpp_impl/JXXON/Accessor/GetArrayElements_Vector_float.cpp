//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/Vector.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetArrayElements<float, Base::Vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<float, Base::Vector>::operator()(Base::Vector<float>& array) const
{
	populateArray<float, Base::Vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asFloat();});
}

template GetArrayElements<float, Base::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<float, Base::Vector>::operator()(Base::Vector<float>& array) const;

template<>
GetArrayElements<double, Base::Vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<double, Base::Vector>::operator()(Base::Vector<double>& array) const
{
	populateArray<double, Base::Vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asDouble();});
}

template GetArrayElements<double, Base::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<double, Base::Vector>::operator()(Base::Vector<double>& array) const;

}} // namespace JXXON::Accessor
