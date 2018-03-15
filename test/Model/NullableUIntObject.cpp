//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/NullableUIntObject.h"

namespace Model {

NullableUIntObject::NullableUIntObject() {
}

NullableUIntObject::NullableUIntObject(const JXXON::Json &json) :
		value(json.get< std::shared_ptr<unsigned int> >("value")) {
}

JXXON::Json NullableUIntObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
