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

template SetArrayElements<bool, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<bool, Polymorphic::List>::operator()(const Json::ArrayBase<bool, Polymorphic::List>& array);

} // namespace Accessor
} // namespace JXXON
