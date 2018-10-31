//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_IsSharedPtr_INCLUDED
#define JXXON_IsSharedPtr_INCLUDED

#include <memory>

namespace JXXON {

/// Trait class identifying T not to be a std::shared_ptr (i.e. non-nullable).
template<typename T>
struct IsSharedPtr : std::false_type
{
};

/// Trait class identifying T as std::shared_ptr (i.e. nullable).
template<typename T>
struct IsSharedPtr<std::shared_ptr<T>> : std::true_type
{
};

} // namespace JXXON

#endif // JXXON_IsSharedPtr_INCLUDED
