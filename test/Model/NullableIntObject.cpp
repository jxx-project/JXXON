//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/NullableIntObject.h"

namespace Model {

NullableIntObject::NullableIntObject() {
}

NullableIntObject::NullableIntObject(const JXXON::Json &json) :
	value(json.get< std::shared_ptr<int> >("value")) {
}

JXXON::Json NullableIntObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
