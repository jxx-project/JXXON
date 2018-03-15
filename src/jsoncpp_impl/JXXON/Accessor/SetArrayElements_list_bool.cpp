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
#include <list>

namespace JXXON {
namespace Accessor {

template SetArrayElements<bool, std::list>::SetArrayElements(Json& json);
template void SetArrayElements<bool, std::list>::operator()(const Json::ArrayBase<bool, std::list>& array);

} // namespace Accessor
} // namespace JXXON
