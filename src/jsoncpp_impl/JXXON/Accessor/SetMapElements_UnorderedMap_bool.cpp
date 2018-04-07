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
#include <Polymorphic/UnorderedMap.h>

namespace JXXON { namespace Accessor {

template SetMapElements<bool, Polymorphic::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<bool, Polymorphic::UnorderedMap>::operator()(const Polymorphic::UnorderedMap<std::string, bool>& map);

}} // namespace JXXON::Accessor
