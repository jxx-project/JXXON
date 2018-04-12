//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/Map.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template GetMapElements<std::shared_ptr<float>, Base::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<float>, Base::Map>::operator()(Base::Map<std::shared_ptr<float>>& map) const;

template GetMapElements<std::shared_ptr<double>, Base::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<double>, Base::Map>::operator()(Base::Map<std::shared_ptr<double>>& map) const;

}} // namespace JXXON::Accessor
