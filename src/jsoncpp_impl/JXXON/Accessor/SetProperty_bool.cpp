//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/SetProperty.hpp"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template SetProperty<bool>::SetProperty(Json& json, const std::string& name);
template void SetProperty<bool>::operator()(const bool& value);

} // namespace Accessor
} // namespace JXXON
