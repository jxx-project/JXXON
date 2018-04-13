//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Serializable_INCLUDED
#define JXXON_Serializable_INCLUDED

#include "JXXON/Json.h"

namespace JXXON {

/// Interface type alias implemented by (de)serializable classes.
using Serializable = Json::Serializable;

} // namespace JXXON

#endif // JXXON_Serializable_INCLUDED
