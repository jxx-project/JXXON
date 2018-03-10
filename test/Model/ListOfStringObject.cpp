//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/ListOfStringObject.hpp"

namespace Model {

ListOfStringObject::ListOfStringObject() {
}

ListOfStringObject::ListOfStringObject(const JXXON::Json &json) :
		value(json.get< JXXON::List< std::string > >("value"))
{
}

JXXON::Json ListOfStringObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
