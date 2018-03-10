//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/SetArrayElements.hpp"
#include <vector>

namespace JXXON {
namespace Accessor {

template SetArrayElements<float, std::vector>::SetArrayElements(Json& json);
template void SetArrayElements<float, std::vector>::operator()(const Json::ArrayBase<float, std::vector>& array);

template SetArrayElements<double, std::vector>::SetArrayElements(Json& json);
template void SetArrayElements<double, std::vector>::operator()(const Json::ArrayBase<double, std::vector>& array);

} // namespace Accessor
} // namespace JXXON
