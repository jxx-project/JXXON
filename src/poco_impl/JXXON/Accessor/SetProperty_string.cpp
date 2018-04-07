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

template SetProperty<std::string>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::string>::operator()(const std::string& value);

}} // namespace JXXON::Accessor
