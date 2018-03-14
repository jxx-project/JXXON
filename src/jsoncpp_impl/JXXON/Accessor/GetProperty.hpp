//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetProperty_INCLUDED
#define JXXON_Accessor_GetProperty_INCLUDED

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template<typename T>
static T getChild(const ::Json::Value& value, const std::string& name, const std::function<T(const ::Json::Value&)>& valueAsT)
{
	if (!value.isNull()) {
		try {
			auto child = value.get(name, ::Json::Value::null);
			if (!child.isNull()) {
				return T(valueAsT(child));
			}
		} catch(std::exception& e) {
			throw Error(e.what());
		}
	}
	return T();
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_GetProperty_INCLUDED
