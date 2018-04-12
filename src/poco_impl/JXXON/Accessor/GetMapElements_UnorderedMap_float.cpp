//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/UnorderedMap.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template GetMapElements<float, Base::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<float, Base::UnorderedMap>::operator()(Base::UnorderedMap<float>& map) const;

template GetMapElements<double, Base::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<double, Base::UnorderedMap>::operator()(Base::UnorderedMap<double>& map) const;

}} // namespace JXXON::Accessor
