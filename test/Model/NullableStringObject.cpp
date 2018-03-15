//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/NullableStringObject.h"

namespace Model {

NullableStringObject::NullableStringObject() {
}

NullableStringObject::NullableStringObject(const JXXON::Json &json) :
	value(json.get< std::shared_ptr<std::string> >("value")) {
}

JXXON::Json NullableStringObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
