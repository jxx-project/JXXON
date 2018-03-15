//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include "JXXON/Accessor/SetArrayElements.tcc"
#include <cstdint>
#include <list>

namespace JXXON {
namespace Accessor {

template SetArrayElements<float, std::list>::SetArrayElements(Json& json);
template void SetArrayElements<float, std::list>::operator()(const Json::ArrayBase<float, std::list>& array);

template SetArrayElements<double, std::list>::SetArrayElements(Json& json);
template void SetArrayElements<double, std::list>::operator()(const Json::ArrayBase<double, std::list>& array);

} // namespace Accessor
} // namespace JXXON
