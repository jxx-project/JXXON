//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/IntMaxObject.h"

namespace Model {

IntMaxObject::IntMaxObject() {
}

IntMaxObject::IntMaxObject(const JXXON::Json &json) :
	value(json.get< std::intmax_t >("value")) {
}

JXXON::Json IntMaxObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
