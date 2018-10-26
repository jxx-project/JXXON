//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Hash_INCLUDED
#define JXXON_Hash_INCLUDED

#include "JXXON/Base/IsSharedPtr.h"

namespace JXXON {

template<typename T, typename Enable = void>
struct Hash;

template<typename T>
struct Hash<T, typename std::enable_if<!IsSharedPtr<T>::value>::type>
{
	std::size_t operator()(const T& arg) const
	{
		return std::hash<T>()(arg);
	}
};

template<typename T>
struct Hash<T, typename std::enable_if<IsSharedPtr<T>::value>::type>
{
	std::size_t operator()(const T& ptr) const
	{
		return ptr ? std::hash<typename T::element_type>()(*ptr) : 0;
	}
};

} // namespace JXXON

#endif // JXXON_Hash_INCLUDED
