//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/UIntMaxObject.hpp"

namespace Model {

UIntMaxObject::UIntMaxObject() {
}

UIntMaxObject::UIntMaxObject(const JXXON::Json &json) :
	value(json.get< std::uintmax_t >("value")) {
}

JXXON::Json UIntMaxObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
