//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/Object.h"

namespace Model {

template<typename T>
Object<T>::Object() {
}

template<typename T>
Object<T>::Object(const JXXON::Json &json) :
	value(json.get<T>("value")) {
}

template<typename T>
JXXON::Json Object<T>::toJson() const {
	JXXON::Json json;
	json.set("value", value);
	return json;
}

} // namespace Model
