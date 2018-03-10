//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/NullableUIntMaxObject.hpp"

namespace Model {

NullableUIntMaxObject::NullableUIntMaxObject() {
}

NullableUIntMaxObject::NullableUIntMaxObject(const JXXON::Json &json) :
	value(json.get< std::shared_ptr<std::uintmax_t> >("value")) {
}

JXXON::Json NullableUIntMaxObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
