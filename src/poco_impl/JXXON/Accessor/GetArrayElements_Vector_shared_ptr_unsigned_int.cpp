//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/Vector.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template GetArrayElements<std::shared_ptr<unsigned int>, Base::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<unsigned int>, Base::Vector>::operator()(Base::Vector<std::shared_ptr<unsigned int>>& array) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template GetArrayElements<std::shared_ptr<std::uint64_t>, Base::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::uint64_t>, Base::Vector>::operator()(Base::Vector<std::shared_ptr<std::uint64_t>>& array) const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template GetArrayElements<std::shared_ptr<std::uintmax_t>, Base::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::uintmax_t>, Base::Vector>::operator()(Base::Vector<std::shared_ptr<std::uintmax_t>>& array) const;
#endif

}} // namespace JXXON::Accessor
