//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/SetMapElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetMapElements<std::shared_ptr<std::string>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::string>>::operator()(const Json::MapType<std::shared_ptr<std::string>>& map);

}} // namespace JXXON::Accessor
