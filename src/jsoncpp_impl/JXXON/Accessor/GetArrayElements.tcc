//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_GetArrayElements_INCLUDED
#define JXXON_Accessor_GetArrayElements_INCLUDED

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"

namespace JXXON { namespace Accessor { namespace {

template<typename T>
void populateArray(Json::ArrayType<T>& array, const ::Json::Value& value, const std::function<T(const ::Json::Value&)>& valueAsT)
{
	if (!value.isNull()) {
		if (value.isArray()) {
			try {
				for (const auto& i : value) {
					array.addElement(i.isNull() ? T() : T(valueAsT(i)));
				}
			} catch (std::exception& e) {
				throw Error(e.what());
			}
		} else {
			throw Error("Not an array");
		}
	}
}

}}} // namespace JXXON::Accessor::

#endif // JXXON_Accessor_GetArrayElements_INCLUDED
