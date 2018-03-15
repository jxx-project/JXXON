//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/NullableBoolObject.h"

namespace Model {

NullableBoolObject::NullableBoolObject() {
}

NullableBoolObject::NullableBoolObject(const JXXON::Json &json) :
	value(json.get< std::shared_ptr<bool> >("value")) {
}

JXXON::Json NullableBoolObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
