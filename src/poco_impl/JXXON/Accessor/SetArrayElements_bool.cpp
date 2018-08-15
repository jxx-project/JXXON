//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/SetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetArrayElements<bool>::SetArrayElements(Json& json);
template void SetArrayElements<bool>::operator()(const Json::ArrayType<bool>& array);

}} // namespace JXXON::Accessor
