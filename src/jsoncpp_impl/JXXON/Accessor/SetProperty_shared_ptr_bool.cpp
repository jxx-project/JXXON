//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/SetProperty_shared_ptr.hpp"

namespace JXXON {
namespace Accessor {

template SetProperty< std::shared_ptr<bool> >::SetProperty(Json& json, const std::string& name);
template void SetProperty< std::shared_ptr<bool> >::operator()(const std::shared_ptr<bool>& value);

} // namespace Accessor
} // namespace JXXON
