//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/IntObject.h"

namespace Model {

IntObject::IntObject() {
}

IntObject::IntObject(const JXXON::Json &json) :
	value(json.get< int >("value")) {
}

JXXON::Json IntObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
