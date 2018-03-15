//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/NullableNestedObject.h"

namespace Model {

NullableNestedObject::NullableNestedObject() {
}

NullableNestedObject::NullableNestedObject(const JXXON::Json &json) :
	value(json.get< std::shared_ptr<Model::NullableStringObject> >("outer")) {
}

JXXON::Json NullableNestedObject::toJson() const {
	JXXON::Json json;
	json.set("outer", value);
	return json;
}

} // namespace Model
