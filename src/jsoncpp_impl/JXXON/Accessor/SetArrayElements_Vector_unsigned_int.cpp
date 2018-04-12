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

template SetArrayElements<unsigned int, Base::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<unsigned int, Base::Vector>::operator()(const Base::Vector<unsigned int>& array);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetArrayElements<std::uint64_t, Base::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::uint64_t, Base::Vector>::operator()(const Base::Vector<std::uint64_t>& array);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetArrayElements<std::uintmax_t, Base::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::uintmax_t, Base::Vector>::operator()(const Base::Vector<std::uintmax_t>& array);
#endif

}} // namespace JXXON::Accessor
