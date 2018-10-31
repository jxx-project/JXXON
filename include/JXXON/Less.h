//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Less_INCLUDED
#define JXXON_Less_INCLUDED

#include "JXXON/IsSharedPtr.h"
#include <functional>

namespace JXXON {

template<typename T, typename Enable = void>
struct Less;

/// Functional forwarding to std::less for non-nullable elements.
template<typename T>
struct Less<T, typename std::enable_if<!IsSharedPtr<T>::value>::type>
{
	bool operator()(const T& lhs, const T& rhs) const
	{
		return std::less<T>()(lhs, rhs);
	}
};

/// Functional forwarding to std::less for nullable element targets. Null elements are considered equal to each other.
template<typename T>
struct Less<T, typename std::enable_if<IsSharedPtr<T>::value>::type>
{
	bool operator()(const T& lhs, const T& rhs) const
	{
		return lhs && rhs ? std::less<typename T::element_type>()(*lhs, *rhs) : lhs || rhs;
	}
};

} // namespace JXXON

#endif // JXXON_Less_INCLUDED
