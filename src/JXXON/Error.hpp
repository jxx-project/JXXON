//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Error_INCLUDED
#define JXXON_Error_INCLUDED

#include <stdexcept>

namespace JXXON {

/// JXXON exception.
struct Error : public std::runtime_error
{
	/// Construct exception for error described by what.
	Error(const std::string& what);

	virtual ~Error();
};

} // namespace JXXON

#endif // JXXON_Error_INCLUDED
