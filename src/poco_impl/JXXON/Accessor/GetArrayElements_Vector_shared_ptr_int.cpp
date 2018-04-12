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

template GetArrayElements<std::shared_ptr<int>, Base::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<int>, Base::Vector>::operator()(Base::Vector<std::shared_ptr<int>>& array) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template GetArrayElements<std::shared_ptr<std::int64_t>, Base::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::int64_t>, Base::Vector>::operator()(Base::Vector<std::shared_ptr<std::int64_t>>& array) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template GetArrayElements<std::shared_ptr<std::intmax_t>, Base::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::intmax_t>, Base::Vector>::operator()(Base::Vector<std::shared_ptr<std::intmax_t>>& array) const;
#endif

}} // namespace JXXON::Accessor
