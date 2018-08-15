//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/SetProperty_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetProperty<std::shared_ptr<float>>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::shared_ptr<float>>::operator()(const std::shared_ptr<float>& value);

template SetProperty<std::shared_ptr<double>>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::shared_ptr<double>>::operator()(const std::shared_ptr<double>& value);

}} // namespace JXXON::Accessor
