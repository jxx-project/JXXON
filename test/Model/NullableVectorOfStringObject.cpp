//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/NullableVectorOfStringObject.hpp"

namespace Model {

NullableVectorOfStringObject::NullableVectorOfStringObject() {
}

NullableVectorOfStringObject::NullableVectorOfStringObject(const JXXON::Json &json) :
	value(json.get< std::shared_ptr< JXXON::Vector< std::shared_ptr<std::string> > > >("value")) {
}

JXXON::Json NullableVectorOfStringObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
