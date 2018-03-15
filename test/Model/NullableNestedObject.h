//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_NullableNestedObject_INCLUDED
#define Model_NullableNestedObject_INCLUDED

#include "JXXON/Serializable.h"
#include "Model/NullableStringObject.h"

namespace Model {

struct NullableNestedObject : public JXXON::Serializable {
	NullableNestedObject();
	NullableNestedObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<Model::NullableStringObject> value;
};

} // namespace Model

#endif // Model_NullableNestedObject_INCLUDED
