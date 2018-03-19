//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetArrayElements_shared_ptr.tcc"
#include <cstdint>
#include <Polymorphic/List.h>

namespace JXXON {
namespace Accessor {

template SetArrayElements<std::shared_ptr<int>, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<int>, Polymorphic::List>::operator()(const Json::ArrayBase<std::shared_ptr<int>, Polymorphic::List>& array);

#if _SIZEOF_INT64_T != _SIZEOF_INT
template SetArrayElements<std::shared_ptr<std::int64_t>, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<std::int64_t>, Polymorphic::List>::operator()(const Json::ArrayBase<std::shared_ptr<std::int64_t>, Polymorphic::List>& array);
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template SetArrayElements<std::shared_ptr<std::intmax_t>, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<std::intmax_t>, Polymorphic::List>::operator()(const Json::ArrayBase<std::shared_ptr<std::intmax_t>, Polymorphic::List>& array);
#endif

} // namespace Accessor
} // namespace JXXON
