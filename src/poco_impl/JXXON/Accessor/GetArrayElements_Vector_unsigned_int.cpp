//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>
#include <Polymorphic/Vector.h>

namespace JXXON {
namespace Accessor {

template GetArrayElements<unsigned int, Polymorphic::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<unsigned int, Polymorphic::Vector>::operator()(Polymorphic::Vector<unsigned int>& array) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template GetArrayElements<std::uint64_t, Polymorphic::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::uint64_t, Polymorphic::Vector>::operator()(Polymorphic::Vector<std::uint64_t>& array) const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template GetArrayElements<std::uintmax_t, Polymorphic::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::uintmax_t, Polymorphic::Vector>::operator()(Polymorphic::Vector<std::uintmax_t>& array) const;
#endif

} // namespace Accessor
} // namespace JXXON
