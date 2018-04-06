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

template SetMapElements<std::shared_ptr<unsigned int>, Polymorphic::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<unsigned int>, Polymorphic::UnorderedMap>::operator()(const Polymorphic::UnorderedMap<std::string, std::shared_ptr<unsigned int>>& map);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetMapElements<std::shared_ptr<std::uint64_t>, Polymorphic::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::uint64_t>, Polymorphic::UnorderedMap>::operator()(const Polymorphic::UnorderedMap<std::string, std::shared_ptr<std::uint64_t>>& map);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetMapElements<std::shared_ptr<std::uintmax_t>, Polymorphic::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::uintmax_t>, Polymorphic::UnorderedMap>::operator()(const Polymorphic::UnorderedMap<std::string, std::shared_ptr<std::uintmax_t>>& map);
#endif

} // namespace Accessor
} // namespace JXXON
