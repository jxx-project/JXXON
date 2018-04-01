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
template void SetArrayElements<float, Polymorphic::List>::operator()(const Polymorphic::List<float>& array);

template SetArrayElements<double, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<double, Polymorphic::List>::operator()(const Polymorphic::List<double>& array);

} // namespace Accessor
} // namespace JXXON
