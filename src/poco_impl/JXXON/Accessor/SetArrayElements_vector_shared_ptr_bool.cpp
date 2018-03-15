//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include "JXXON/Accessor/SetArrayElements_shared_ptr.tcc"
#include <cstdint>
#include <vector>

namespace JXXON {
namespace Accessor {

template SetArrayElements<std::shared_ptr<bool>, std::vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<bool>, std::vector>::operator()(const Json::ArrayBase<std::shared_ptr<bool>, std::vector>& array);

} // namespace Accessor
} // namespace JXXON
