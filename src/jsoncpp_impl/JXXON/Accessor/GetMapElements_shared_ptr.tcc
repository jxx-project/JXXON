//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Accessor_GetMapElements_shared_ptr_INCLUDED
#define JXXON_Accessor_GetMapElements_shared_ptr_INCLUDED

namespace JXXON { namespace Accessor {
namespace {

template<typename T>
void populateMap(Json::MapType<T>& map, const ::Json::Value& value, const std::function<typename T::element_type(const ::Json::Value::const_iterator&)>& valueAsT)
{
	if (!value.isNull()) {
		if (value.isObject()) {
			try {
				for (auto i = value.begin(); i != value.end(); ++i) {
					map.addElement(i.key().asString(), i->isNull() ? T() : std::make_shared<typename T::element_type>(valueAsT(i)));
				}
			} catch (std::exception& e) {
				throw Error(e.what());
			}
		} else {
			throw Error("Not an object");
		}
	}
}

} // namespace
}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_GetMapElements_shared_ptr_INCLUDED
