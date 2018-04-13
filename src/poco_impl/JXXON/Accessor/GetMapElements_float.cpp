//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template GetMapElements<float>::GetMapElements(const Json& json);
template void GetMapElements<float>::operator()(Json::MapType<float>& map) const;

template GetMapElements<double>::GetMapElements(const Json& json);
template void GetMapElements<double>::operator()(Json::MapType<double>& map) const;

}} // namespace JXXON::Accessor
