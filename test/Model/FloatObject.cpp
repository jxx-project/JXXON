//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/FloatObject.h"

namespace Model {

FloatObject::FloatObject() {
}

FloatObject::FloatObject(const JXXON::Json &json) :
	value(json.get< float >("value")) {
}

JXXON::Json FloatObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
