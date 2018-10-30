//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Deque_INCLUDED
#define JXXON_Deque_INCLUDED

#include "JXXON/Base/Deque.h"
#include "JXXON/Json.h"

namespace JXXON {

/// Alias template composing std::deque<T, Allocator> and implementing JXXON::Serializable.
template<typename T, typename Allocator = std::allocator<T>>
using Deque = Json::Array<T, Base::Deque, Allocator>;

} // namespace JXXON

#endif // JXXON_Deque_INCLUDED
