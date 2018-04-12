//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/UnorderedMap.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetMapElements<bool, Base::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<bool, Base::UnorderedMap>::operator()(const Base::UnorderedMap<bool>& map);

}} // namespace JXXON::Accessor
