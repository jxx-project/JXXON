//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Error_INCLUDED
#define JXXON_Error_INCLUDED

#include <stdexcept>

namespace JXXON {
  
struct Error : public std::runtime_error
/// JXXON exception.
{
	Error(const std::string what);
	  
	virtual ~Error();
};

} // namespace JXXON

#endif // JXXON_Error_INCLUDED
