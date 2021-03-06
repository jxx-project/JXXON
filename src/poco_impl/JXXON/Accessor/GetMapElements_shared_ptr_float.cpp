//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template GetMapElements<std::shared_ptr<float>>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<float>>::operator()(Json::MapType<std::shared_ptr<float>>& map) const;

template GetMapElements<std::shared_ptr<double>>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<double>>::operator()(Json::MapType<std::shared_ptr<double>>& map) const;

}} // namespace JXXON::Accessor
