//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/NullableDoubleObject.h"

namespace Model {

NullableDoubleObject::NullableDoubleObject() {
}

NullableDoubleObject::NullableDoubleObject(const JXXON::Json &json) :
	value(json.get< std::shared_ptr<double> >("value")) {
}

JXXON::Json NullableDoubleObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
