//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements.tcc"
#include <cstdint>
#include <Polymorphic/Map.h>

namespace JXXON { namespace Accessor {

template SetMapElements<bool, Polymorphic::Map>::SetMapElements(Json& json);
template void SetMapElements<bool, Polymorphic::Map>::operator()(const Polymorphic::Map<std::string, bool>& map);

}} // namespace JXXON::Accessor
