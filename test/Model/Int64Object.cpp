//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/Int64Object.hpp"

namespace Model {

Int64Object::Int64Object() {
}

Int64Object::Int64Object(const JXXON::Json &json) :
	value(json.get< std::int64_t >("value")) {
}

JXXON::Json Int64Object::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
