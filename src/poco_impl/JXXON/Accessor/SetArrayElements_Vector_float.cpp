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

template SetArrayElements<float, Polymorphic::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<float, Polymorphic::Vector>::operator()(const Json::ArrayBase<float, Polymorphic::Vector>& array);

template SetArrayElements<double, Polymorphic::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<double, Polymorphic::Vector>::operator()(const Json::ArrayBase<double, Polymorphic::Vector>& array);

} // namespace Accessor
} // namespace JXXON
