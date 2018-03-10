//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/DoubleObject.hpp"

namespace Model {

DoubleObject::DoubleObject() {
}

DoubleObject::DoubleObject(const JXXON::Json &json) :
	value(json.get< double >("value")) {
}

JXXON::Json DoubleObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
