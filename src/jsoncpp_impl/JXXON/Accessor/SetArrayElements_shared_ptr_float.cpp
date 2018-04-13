//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetArrayElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetArrayElements<std::shared_ptr<float>>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<float>>::operator()(const Json::ArrayType<std::shared_ptr<float>>& array);

template SetArrayElements<std::shared_ptr<double>>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<double>>::operator()(const Json::ArrayType<std::shared_ptr<double>>& array);

}} // namespace JXXON::Accessor
