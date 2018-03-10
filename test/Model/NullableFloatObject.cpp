//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/NullableFloatObject.hpp"

namespace Model {

NullableFloatObject::NullableFloatObject() {
}

NullableFloatObject::NullableFloatObject(const JXXON::Json &json) :
	value(json.get< std::shared_ptr<float> >("value")) {
}

JXXON::Json NullableFloatObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
