//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetArrayElements_INCLUDED
#define JXXON_Accessor_GetArrayElements_INCLUDED

namespace JXXON { namespace Accessor {
namespace {

template<class T, template<typename...> class Base>
void populateArray(Base<T>& array, const ::Json::Value& value, const std::function<T(const ::Json::Value&)>& valueAsT)
{
	array.clear();
	if (!value.isNull()) {
		if (value.isArray()) {
			try {
				for (const auto& i : value) {
					array.emplace_back(i.isNull() ?  T() : T(valueAsT(i)));
				}
			} catch (std::exception& e) {
				throw Error(e.what());
			}
		} else {
			throw Error("Not an array");
		}
	}
}

} // namespace
}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_GetArrayElements_INCLUDED
