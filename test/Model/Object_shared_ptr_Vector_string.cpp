//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXON/Vector.h"
#include <memory>
#include <string>
#include "Model/Object.tcc"

namespace Model {

template class Object< std::shared_ptr< JXXON::Vector<std::string> > >;

} // namespace Model
