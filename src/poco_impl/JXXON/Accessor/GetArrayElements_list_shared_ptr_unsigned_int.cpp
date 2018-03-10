//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetArrayElements_shared_ptr.hpp"
#include <list>

namespace JXXON {
namespace Accessor {

template GetArrayElements<std::shared_ptr<unsigned int>, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<unsigned int>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<unsigned int>, std::list>& array) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template GetArrayElements<std::shared_ptr<std::uint64_t>, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::uint64_t>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<std::uint64_t>, std::list>& array) const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template GetArrayElements<std::shared_ptr<std::uintmax_t>, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::uintmax_t>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<std::uintmax_t>, std::list>& array) const;
#endif

} // namespace Accessor
} // namespace JXXON
