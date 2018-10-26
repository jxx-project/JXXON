//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_IsSharedPtr_INCLUDED
#define JXXON_IsSharedPtr_INCLUDED

namespace JXXON {

template<typename T>
struct IsSharedPtr : std::false_type
{
};

template<typename T>
struct IsSharedPtr<std::shared_ptr<T>> : std::true_type
{
};

} // namespace JXXON

#endif // JXXON_IsSharedPtr_INCLUDED
