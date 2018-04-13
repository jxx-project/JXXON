//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED
#define JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED

namespace JXXON { namespace Accessor {
namespace {

template<typename T>
void populateArray(Json::ArrayType<T>& array, const ::Json::Value& value, const std::function<typename T::element_type(const ::Json::Value&)>& valueAsT)
{
	if (!value.isNull()) {
		if (value.isArray()) {
			try {
				for (const auto& i : value) {
					array.addElement(i.isNull() ? T() : std::make_shared<typename T::element_type>(valueAsT(i)));
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

#endif // JXXON_Accessor_GetArrayElements_shared_ptr_INCLUDED
