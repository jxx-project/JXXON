//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/SetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetMapElements<bool>::SetMapElements(Json& json);
template void SetMapElements<bool>::operator()(const Json::MapType<bool>& map);

}} // namespace JXXON::Accessor
