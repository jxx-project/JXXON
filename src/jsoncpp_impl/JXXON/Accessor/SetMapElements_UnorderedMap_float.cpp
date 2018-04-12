//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/UnorderedMap.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetMapElements<float, Base::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<float, Base::UnorderedMap>::operator()(const Base::UnorderedMap<float>& map);

template SetMapElements<double, Base::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<double, Base::UnorderedMap>::operator()(const Base::UnorderedMap<double>& map);

}} // namespace JXXON::Accessor
