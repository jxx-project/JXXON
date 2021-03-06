//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/SetArrayElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetArrayElements<std::shared_ptr<std::string>>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<std::string>>::operator()(const Json::ArrayType<std::shared_ptr<std::string>>& array);

}} // namespace JXXON::Accessor
