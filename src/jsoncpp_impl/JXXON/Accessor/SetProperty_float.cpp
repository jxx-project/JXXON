//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/SetProperty.hpp"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template SetProperty<float>::SetProperty(Json& json, const std::string& name);
template void SetProperty<float>::operator()(const float& value);

template SetProperty<double>::SetProperty(Json& json, const std::string& name);
template void SetProperty<double>::operator()(const double& value);

} // namespace Accessor
} // namespace JXXON
