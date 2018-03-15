//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/StringObject.h"

namespace Model {

StringObject::StringObject() {
}

StringObject::StringObject(const JXXON::Json &json) :
	value(json.get< std::string >("value")) {
}

JXXON::Json StringObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
