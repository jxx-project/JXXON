//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/NullableListOfStringObject.hpp"

namespace Model {

NullableListOfStringObject::NullableListOfStringObject() {
}

NullableListOfStringObject::NullableListOfStringObject(const JXXON::Json &json) :
		value(json.get< std::shared_ptr< JXXON::List< std::shared_ptr<std::string> > > >("value"))
{
}

JXXON::Json NullableListOfStringObject::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
