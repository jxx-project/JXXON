//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/UnorderedMap.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetMapElements<std::shared_ptr<bool>, Base::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<bool>, Base::UnorderedMap>::operator()(const Base::UnorderedMap<std::shared_ptr<bool>>& map);

}} // namespace JXXON::Accessor
