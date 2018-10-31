//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_EqualTo_INCLUDED
#define JXXON_EqualTo_INCLUDED

#include "JXXON/IsSharedPtr.h"
#include <functional>

namespace JXXON {

template<typename T, typename Enable = void>
struct EqualTo;

/// Functional forwarding to std::equal_to for non-nullable elements.
template<typename T>
struct EqualTo<T, typename std::enable_if<!IsSharedPtr<T>::value>::type>
{
	bool operator()(const T& lhs, const T& rhs) const
	{
		return std::equal_to<T>()(lhs, rhs);
	}
};

/// Functional forwarding to std::equal_to for nullable element targets. Null elements are considered equal to each other.
template<typename T>
struct EqualTo<T, typename std::enable_if<IsSharedPtr<T>::value>::type>
{
	bool operator()(const T& lhs, const T& rhs) const
	{
		return lhs && rhs ? std::equal_to<typename T::element_type>()(*lhs, *rhs) : !lhs && !rhs;
	}
};

} // namespace JXXON

#endif // JXXON_EqualTo_INCLUDED
