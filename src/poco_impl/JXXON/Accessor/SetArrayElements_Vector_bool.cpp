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
#include <Polymorphic/Vector.h>

namespace JXXON {
namespace Accessor {

template SetArrayElements<bool, Polymorphic::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<bool, Polymorphic::Vector>::operator()(const Json::ArrayBase<bool, Polymorphic::Vector>& array);

} // namespace Accessor
} // namespace JXXON
