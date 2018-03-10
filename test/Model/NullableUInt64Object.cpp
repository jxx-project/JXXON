//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/NullableUInt64Object.hpp"

namespace Model {

NullableUInt64Object::NullableUInt64Object() {
}

NullableUInt64Object::NullableUInt64Object(const JXXON::Json &json) :
	value(json.get< std::shared_ptr<std::uint64_t> >("value")) {
}

JXXON::Json NullableUInt64Object::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
