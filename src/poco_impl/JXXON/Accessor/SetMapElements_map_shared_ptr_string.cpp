//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/SetMapElements_shared_ptr.hpp"
#include <map>

namespace JXXON {
namespace Accessor {

template SetMapElements<std::shared_ptr<std::string>, std::map>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::string>, std::map>::operator()(const Json::MapBase<std::shared_ptr<std::string>, std::map>& map);

} // namespace Accessor
} // namespace JXXON
