//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetArrayElements_INCLUDED
#define JXXON_Accessor_GetArrayElements_INCLUDED

namespace JXXON {
namespace Accessor {

template<class T, template<typename...> class Base>
static void populateArray(Json::ArrayBase<T, Base>& array, const ::Json::Value& value, const std::function<T(const ::Json::Value::const_iterator&)>& valueAsT)
{
	array.clear();
	if (!value.isNull()) {
		if (value.isArray()) {
			try {
				for (auto i = value.begin(); i != value.end(); ++i) {
					array.emplace_back(i->isNull() ?  T() : T(valueAsT(i)));
				}
			} catch (std::exception& e) {
				throw Error(e.what());
			}
		} else {
			throw Error("Not an array");
		}
	}
}

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_GetArrayElements_INCLUDED
