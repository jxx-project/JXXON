//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/UInt64Object.h"

namespace Model {

UInt64Object::UInt64Object() {
}

UInt64Object::UInt64Object(const JXXON::Json &json) :
	value(json.get< std::uint64_t >("value")) {
}

JXXON::Json UInt64Object::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
