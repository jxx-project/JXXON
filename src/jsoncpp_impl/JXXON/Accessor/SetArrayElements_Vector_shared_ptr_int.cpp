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
#include <Polymorphic/Vector.h>

namespace JXXON {
namespace Accessor {

template SetArrayElements<std::shared_ptr<int>, Polymorphic::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<int>, Polymorphic::Vector>::operator()(const Polymorphic::Vector<std::shared_ptr<int>>& array);

#if _SIZEOF_INT64_T != _SIZEOF_INT
template SetArrayElements<std::shared_ptr<std::int64_t>, Polymorphic::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<std::int64_t>, Polymorphic::Vector>::operator()(const Polymorphic::Vector<std::shared_ptr<std::int64_t>>& array);
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template SetArrayElements<std::shared_ptr<std::intmax_t>, Polymorphic::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<std::intmax_t>, Polymorphic::Vector>::operator()(const Polymorphic::Vector<std::shared_ptr<std::intmax_t>>& array);
#endif

} // namespace Accessor
} // namespace JXXON
