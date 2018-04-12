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

template SetMapElements<std::string, Base::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::string, Base::UnorderedMap>::operator()(const Base::UnorderedMap<std::string>& map);

}} // namespace JXXON::Accessor
