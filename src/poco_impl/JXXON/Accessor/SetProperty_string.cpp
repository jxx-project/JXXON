//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/SetProperty.hpp"

namespace JXXON {
namespace Accessor {

template SetProperty<std::string>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::string>::operator()(const std::string& value);

} // namespace Accessor
} // namespace JXXON
