//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/Vector.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetArrayElements<int, Base::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<int, Base::Vector>::operator()(const Base::Vector<int>& array);

#if _SIZEOF_INT64_T != _SIZEOF_INT
template SetArrayElements<std::int64_t, Base::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::int64_t, Base::Vector>::operator()(const Base::Vector<std::int64_t>& array);
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template SetArrayElements<std::intmax_t, Base::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::intmax_t, Base::Vector>::operator()(const Base::Vector<std::intmax_t>& array);
#endif

}} // namespace JXXON::Accessor
