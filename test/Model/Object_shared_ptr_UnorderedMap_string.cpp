//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/UnorderedMap.h"
#include "Model/Object.tcc"
#include <memory>
#include <string>

namespace Model {

template struct Object<std::shared_ptr<JXXON::UnorderedMap<std::string>>>;

} // namespace Model
