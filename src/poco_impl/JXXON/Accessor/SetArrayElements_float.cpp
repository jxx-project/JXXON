//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetArrayElements<float>::SetArrayElements(Json& json);
template void SetArrayElements<float>::operator()(const Json::ArrayType<float>& array);

template SetArrayElements<double>::SetArrayElements(Json& json);
template void SetArrayElements<double>::operator()(const Json::ArrayType<double>& array);

}} // namespace JXXON::Accessor
