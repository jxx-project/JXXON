//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetProperty.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetProperty<bool>::SetProperty(Json& json, const std::string& name);
template void SetProperty<bool>::operator()(const bool& value);

}} // namespace JXXON::Accessor
