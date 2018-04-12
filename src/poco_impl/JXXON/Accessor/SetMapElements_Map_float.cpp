//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/Map.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetMapElements<float, Base::Map>::SetMapElements(Json& json);
template void SetMapElements<float, Base::Map>::operator()(const Base::Map<float>& map);

template SetMapElements<double, Base::Map>::SetMapElements(Json& json);
template void SetMapElements<double, Base::Map>::operator()(const Base::Map<double>& map);

}} // namespace JXXON::Accessor
