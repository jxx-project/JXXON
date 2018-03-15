//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_NestedObject_INCLUDED
#define Model_NestedObject_INCLUDED

#include "JXXON/Serializable.h"
#include "Model/StringObject.h"

namespace Model {

struct NestedObject : public JXXON::Serializable {
	NestedObject();
	NestedObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	Model::StringObject value;
};

} // namespace Model

#endif // Model_NestedObject_INCLUDED
