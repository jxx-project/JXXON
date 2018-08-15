//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/SetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetMapElements<std::string>::SetMapElements(Json& json);
template void SetMapElements<std::string>::operator()(const Json::MapType<std::string>& map);

}} // namespace JXXON::Accessor
