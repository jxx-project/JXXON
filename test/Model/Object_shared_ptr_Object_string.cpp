//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include <memory>
#include <string>
#include "Model/Object.tcc"

namespace Model {

template class Object< std::shared_ptr< Object<std::string> > >;

} // namespace Model