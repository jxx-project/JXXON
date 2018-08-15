//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/List.h"
#include "Model/Object.tcc"
#include <string>

namespace Model {

template struct Object<JXXON::List<std::string>>;

} // namespace Model
