//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Model/Object.tcc"
#include <memory>
#include <string>

namespace Model {

template struct Object<std::shared_ptr<std::string>>;

} // namespace Model
