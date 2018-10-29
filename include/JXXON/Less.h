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

template<typename T>
struct Less<T, typename std::enable_if<!IsSharedPtr<T>::value>::type>
{
	bool operator()(const T& lhs, const T& rhs) const
	{
		return std::less<T>()(lhs, rhs);
	}
};

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
