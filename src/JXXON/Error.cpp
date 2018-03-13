//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:     BSL-1.0
//


#include "JXXON/Error.hpp"

namespace JXXON {

Error::Error(const std::string& what) : std::runtime_error(what)
{
}

Error::~Error()
{
}

} // namespace JXXON
