//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>
#include <Polymorphic/UnorderedMap.h>

namespace JXXON { namespace Accessor {

template GetMapElements<std::shared_ptr<int>, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<int>, Polymorphic::UnorderedMap>::operator()(Polymorphic::UnorderedMap<std::string, std::shared_ptr<int>>& map) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template GetMapElements<std::shared_ptr<std::int64_t>, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::int64_t>, Polymorphic::UnorderedMap>::operator()(Polymorphic::UnorderedMap<std::string, std::shared_ptr<std::int64_t>>& map) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template GetMapElements<std::shared_ptr<std::intmax_t>, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::intmax_t>, Polymorphic::UnorderedMap>::operator()(Polymorphic::UnorderedMap<std::string, std::shared_ptr<std::intmax_t>>& map) const;
#endif

}} // namespace JXXON::Accessor