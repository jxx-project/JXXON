//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/NestedObject.hpp"

namespace Model {

NestedObject::NestedObject() {
}

NestedObject::NestedObject(const JXXON::Json &json) :
	value(json.get< Model::StringObject >("outer")) {
}

JXXON::Json NestedObject::toJson() const {
	JXXON::Json json;
	json.set("outer", value);
	return json;
}

} // namespace Model
