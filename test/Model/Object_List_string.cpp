//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXON/List.h"
#include <string>
#include "Model/Object.tcc"

namespace Model {

template struct Object<JXXON::List<std::string>>;

} // namespace Model
