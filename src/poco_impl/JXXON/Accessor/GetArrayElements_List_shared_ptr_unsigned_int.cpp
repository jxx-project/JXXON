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

namespace JXXON {
namespace Accessor {

template GetArrayElements<std::shared_ptr<unsigned int>, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<unsigned int>, Polymorphic::List>::operator()(Json::ArrayBase<std::shared_ptr<unsigned int>, Polymorphic::List>& array) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template GetArrayElements<std::shared_ptr<std::uint64_t>, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::uint64_t>, Polymorphic::List>::operator()(Json::ArrayBase<std::shared_ptr<std::uint64_t>, Polymorphic::List>& array) const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template GetArrayElements<std::shared_ptr<std::uintmax_t>, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::uintmax_t>, Polymorphic::List>::operator()(Json::ArrayBase<std::shared_ptr<std::uintmax_t>, Polymorphic::List>& array) const;
#endif

} // namespace Accessor
} // namespace JXXON