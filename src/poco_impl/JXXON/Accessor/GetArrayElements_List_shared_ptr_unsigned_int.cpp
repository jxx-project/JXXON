//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements_shared_ptr.tcc"
#include <cstdint>
#include <Polymorphic/List.h>

namespace JXXON { namespace Accessor {

template GetArrayElements<std::shared_ptr<unsigned int>, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<unsigned int>, Polymorphic::List>::operator()(Polymorphic::List<std::shared_ptr<unsigned int>>& array) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template GetArrayElements<std::shared_ptr<std::uint64_t>, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::uint64_t>, Polymorphic::List>::operator()(Polymorphic::List<std::shared_ptr<std::uint64_t>>& array) const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template GetArrayElements<std::shared_ptr<std::uintmax_t>, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::uintmax_t>, Polymorphic::List>::operator()(Polymorphic::List<std::shared_ptr<std::uintmax_t>>& array) const;
#endif

}} // namespace JXXON::Accessor
