//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/SetArrayElements_shared_ptr.hpp"
#include <cstdint>
#include <vector>

namespace JXXON {
namespace Accessor {

template SetArrayElements<std::shared_ptr<float>, std::vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<float>, std::vector>::operator()(const Json::ArrayBase<std::shared_ptr<float>, std::vector>& array);

template SetArrayElements<std::shared_ptr<double>, std::vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<double>, std::vector>::operator()(const Json::ArrayBase<std::shared_ptr<double>, std::vector>& array);

} // namespace Accessor
} // namespace JXXON
