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

template SetArrayElements<std::string, std::list>::SetArrayElements(Json& json);
template void SetArrayElements<std::string, std::list>::operator()(const Json::ArrayBase<std::string, std::list>& array);

} // namespace Accessor
} // namespace JXXON
