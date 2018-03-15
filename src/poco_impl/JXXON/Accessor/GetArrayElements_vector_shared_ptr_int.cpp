//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include "JXXON/Accessor/GetArrayElements_shared_ptr.tcc"
#include <cstdint>
#include <vector>

namespace JXXON {
namespace Accessor {

template GetArrayElements<std::shared_ptr<int>, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<int>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<int>, std::vector>& array) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template GetArrayElements<std::shared_ptr<std::int64_t>, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::int64_t>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<std::int64_t>, std::vector>& array) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template GetArrayElements<std::shared_ptr<std::intmax_t>, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::intmax_t>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<std::intmax_t>, std::vector>& array) const;
#endif

} // namespace Accessor
} // namespace JXXON
