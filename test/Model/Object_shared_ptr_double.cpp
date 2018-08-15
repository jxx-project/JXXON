//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Model/Object.tcc"
#include <memory>

namespace Model {

template struct Object<std::shared_ptr<double>>;

} // namespace Model
