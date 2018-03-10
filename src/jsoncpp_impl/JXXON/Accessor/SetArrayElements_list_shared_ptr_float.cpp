//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/SetArrayElements_shared_ptr.hpp"
#include <list>

namespace JXXON {
namespace Accessor {

template SetArrayElements<std::shared_ptr<float>, std::list>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<float>, std::list>::operator()(const Json::ArrayBase<std::shared_ptr<float>, std::list>& array);

template SetArrayElements<std::shared_ptr<double>, std::list>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<double>, std::list>::operator()(const Json::ArrayBase<std::shared_ptr<double>, std::list>& array);

} // namespace Accessor
} // namespace JXXON
