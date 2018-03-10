//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_NestedObject_INCLUDED
#define Model_NestedObject_INCLUDED

#include "JXXON/Serializable.hpp"
#include "Model/StringObject.hpp"

namespace Model {

struct NestedObject : public JXXON::Serializable {
	NestedObject();
	NestedObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	Model::StringObject value;
};

} // namespace Model

#endif // Model_NestedObject_INCLUDED
