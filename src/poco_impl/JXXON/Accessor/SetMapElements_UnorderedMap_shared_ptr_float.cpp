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

template SetMapElements<std::shared_ptr<float>, Polymorphic::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<float>, Polymorphic::UnorderedMap>::operator()(const Polymorphic::UnorderedMap<std::string, std::shared_ptr<float>>& map);

template SetMapElements<std::shared_ptr<double>, Polymorphic::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<double>, Polymorphic::UnorderedMap>::operator()(const Polymorphic::UnorderedMap<std::string, std::shared_ptr<double>>& map);

} // namespace Accessor
} // namespace JXXON
