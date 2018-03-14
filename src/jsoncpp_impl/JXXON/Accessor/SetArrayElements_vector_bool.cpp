//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/SetArrayElements.hpp"
#include <cstdint>
#include <vector>

namespace JXXON {
namespace Accessor {

template SetArrayElements<bool, std::vector>::SetArrayElements(Json& json);
template void SetArrayElements<bool, std::vector>::operator()(const Json::ArrayBase<bool, std::vector>& array);

} // namespace Accessor
} // namespace JXXON
