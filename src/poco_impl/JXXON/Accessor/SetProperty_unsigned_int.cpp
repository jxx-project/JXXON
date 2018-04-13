//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetProperty.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetProperty<unsigned int>::SetProperty(Json& json, const std::string& name);
template void SetProperty<unsigned int>::operator()(const unsigned int& value);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetProperty<std::uint64_t>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::uint64_t>::operator()(const std::uint64_t& value);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetProperty<std::uintmax_t>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::uintmax_t>::operator()(const std::uintmax_t& value);
#endif

}} // namespace JXXON::Accessor
