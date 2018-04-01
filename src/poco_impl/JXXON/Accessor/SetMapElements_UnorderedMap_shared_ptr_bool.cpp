//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements_shared_ptr.tcc"
#include <cstdint>
#include <Polymorphic/UnorderedMap.h>

namespace JXXON {
namespace Accessor {

template SetMapElements<std::shared_ptr<bool>, Polymorphic::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<bool>, Polymorphic::UnorderedMap>::operator()(const Polymorphic::UnorderedMap< std::string, std::shared_ptr<bool> >& map);

} // namespace Accessor
} // namespace JXXON
