//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED
#define JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED

namespace JXXON {
namespace Accessor {

template<class T, template<typename...> class Base>
static void populateArray(Json::ArrayBase<T, Base>& array, const ::Json::Value& value, const std::function<typename T::element_type(const ::Json::Value::const_iterator&)>& valueAsT)
{
	array.clear();
	if (!value.isNull()) {
		if (value.isArray()) {
			try {
				for (auto i = value.begin(); i != value.end(); ++i) {
					array.emplace_back(i->isNull() ? T() : std::make_shared<typename T::element_type>(valueAsT(i)));
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

#endif // JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED
