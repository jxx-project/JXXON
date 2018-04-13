//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include <memory>
#include "Model/Object.tcc"

namespace Model {

template struct Object<std::shared_ptr<bool>>;

} // namespace Model
