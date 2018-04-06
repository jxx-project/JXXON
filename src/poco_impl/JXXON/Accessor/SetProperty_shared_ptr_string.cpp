//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetProperty_shared_ptr.tcc"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template SetProperty<std::shared_ptr<std::string>>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::shared_ptr<std::string>>::operator()(const std::shared_ptr<std::string>& value);

} // namespace Accessor
} // namespace JXXON
