//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include <string>
#include "Model/Object.tcc"

namespace Model {

template struct Object<Object<std::string>>;

} // namespace Model
