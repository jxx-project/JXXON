//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetArrayElements.tcc"
#include <cstdint>
#include <Polymorphic/List.h>

namespace JXXON {
namespace Accessor {

template SetArrayElements<float, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<float, Polymorphic::List>::operator()(const Json::ArrayBase<float, Polymorphic::List>& array);

template SetArrayElements<double, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<double, Polymorphic::List>::operator()(const Json::ArrayBase<double, Polymorphic::List>& array);

} // namespace Accessor
} // namespace JXXON
