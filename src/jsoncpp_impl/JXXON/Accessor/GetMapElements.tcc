//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetMapElements_INCLUDED
#define JXXON_Accessor_GetMapElements_INCLUDED

namespace JXXON {
namespace Accessor {
namespace {

template<typename T, template<typename...> class Base>
void populateMap(Json::MapBase<T, Base>& map, const ::Json::Value& value, const std::function<T(const ::Json::Value::const_iterator&)>& valueAsT)
{
	map.clear();
	if (!value.isNull()) {
		if (value.isObject()) {
			try {
				for (auto i = value.begin(); i != value.end(); ++i) {
					map.emplace(i.key().asString(), i->isNull() ?  T() : T(valueAsT(i)));
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
} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Accessor_GetMapElements_INCLUDED