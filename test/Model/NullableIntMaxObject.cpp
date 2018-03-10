//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/NullableIntMaxObject.hpp"

namespace Model {

NullableIntMaxObject::NullableIntMaxObject() {
}

NullableIntMaxObject::NullableIntMaxObject(const JXXON::Json &json) :
	value(json.get< std::shared_ptr<std::intmax_t> >("value")) {
}

JXXON::Json NullableIntMaxObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
