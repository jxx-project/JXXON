//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include "JXXON/Accessor/SetProperty_shared_ptr.tcc"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template SetProperty< std::shared_ptr<unsigned int> >::SetProperty(Json& json, const std::string& name);
template void SetProperty< std::shared_ptr<unsigned int> >::operator()(const std::shared_ptr<unsigned int>& value);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetProperty< std::shared_ptr<std::uint64_t> >::SetProperty(Json& json, const std::string& name);
template void SetProperty< std::shared_ptr<std::uint64_t> >::operator()(const std::shared_ptr<std::uint64_t>& value);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetProperty< std::shared_ptr<std::uintmax_t> >::SetProperty(Json& json, const std::string& name);
template void SetProperty< std::shared_ptr<std::uintmax_t> >::operator()(const std::shared_ptr<std::uintmax_t>& value);
#endif

} // namespace Accessor
} // namespace JXXON
