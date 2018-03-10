//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/UIntObject.hpp"

namespace Model {

UIntObject::UIntObject() {
}

UIntObject::UIntObject(const JXXON::Json &json) :
		value(json.get< unsigned int >("value")) {
}

JXXON::Json UIntObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
