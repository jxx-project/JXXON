//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetMapElements<float>::SetMapElements(Json& json);
template void SetMapElements<float>::operator()(const Json::MapType<float>& map);

template SetMapElements<double>::SetMapElements(Json& json);
template void SetMapElements<double>::operator()(const Json::MapType<double>& map);

}} // namespace JXXON::Accessor
