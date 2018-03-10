//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/VectorOfStringObject.hpp"

namespace Model {

VectorOfStringObject::VectorOfStringObject() {
}

VectorOfStringObject::VectorOfStringObject(const JXXON::Json &json) :
	value(json.get< JXXON::Vector< std::string > >("value")) {
}

JXXON::Json VectorOfStringObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
