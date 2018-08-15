//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/SetMapElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetMapElements<std::shared_ptr<float>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<float>>::operator()(const Json::MapType<std::shared_ptr<float>>& map);

template SetMapElements<std::shared_ptr<double>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<double>>::operator()(const Json::MapType<std::shared_ptr<double>>& map);

}} // namespace JXXON::Accessor
