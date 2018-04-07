//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>
#include <Polymorphic/Map.h>

namespace JXXON { namespace Accessor {

template GetMapElements<float, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<float, Polymorphic::Map>::operator()(Polymorphic::Map<std::string, float>& map) const;

template GetMapElements<double, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<double, Polymorphic::Map>::operator()(Polymorphic::Map<std::string, double>& map) const;

}} // namespace JXXON::Accessor
