//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/BoolObject.hpp"

namespace Model {

BoolObject::BoolObject() {
}

BoolObject::BoolObject(const JXXON::Json &json) :
	value(json.get< bool >("value")) {
}

JXXON::Json BoolObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
