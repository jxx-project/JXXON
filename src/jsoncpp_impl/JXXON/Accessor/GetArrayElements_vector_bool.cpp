//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>
#include <vector>

namespace JXXON {
namespace Accessor {

namespace {

template<>
void populateArray<bool, std::vector>(Json::ArrayBase<bool, std::vector>& array, const ::Json::Value& value, const std::function<bool(const ::Json::Value::const_iterator&)>& valueAsT)
{
	array.clear();
	if (!value.isNull()) {
		if (value.isArray()) {
			try {
				for (auto i = value.begin(); i != value.end(); ++i) {
					array.push_back(i->isNull() ?  bool() : bool(valueAsT(i)));
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

template<>
GetArrayElements<bool, std::vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<bool, std::vector>::operator()(Json::ArrayBase<bool, std::vector>& array) const
{
	populateArray<bool, std::vector>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asBool();});
}

template GetArrayElements<bool, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<bool, std::vector>::operator()(Json::ArrayBase<bool, std::vector>& array) const;

} // namespace Accessor
} // namespace JXXON
