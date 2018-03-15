//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/NullableInt64Object.h"

namespace Model {

NullableInt64Object::NullableInt64Object() {
}

NullableInt64Object::NullableInt64Object(const JXXON::Json &json) :
	value(json.get< std::shared_ptr<std::int64_t> >("value")) {
}

JXXON::Json NullableInt64Object::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
