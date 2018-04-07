//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetProperty_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetProperty<std::shared_ptr<int>>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::shared_ptr<int>>::operator()(const std::shared_ptr<int>& value);

#if _SIZEOF_INT64_T != _SIZEOF_INT
template SetProperty<std::shared_ptr<std::int64_t>>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::shared_ptr<std::int64_t>>::operator()(const std::shared_ptr<std::int64_t>& value);
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template SetProperty<std::shared_ptr<std::intmax_t>>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::shared_ptr<std::intmax_t>>::operator()(const std::shared_ptr<std::intmax_t>& value);
#endif

}} // namespace JXXON::Accessor
