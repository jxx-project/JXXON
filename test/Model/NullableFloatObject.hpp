//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_NullableFloatObject_INCLUDED
#define Model_NullableFloatObject_INCLUDED

#include "JXXON/Serializable.hpp"

namespace Model {

struct NullableFloatObject : public JXXON::Serializable {
	NullableFloatObject();
	NullableFloatObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<float> value;
};

} // namespace Model

#endif // Model_NullableFloatObject_INCLUDED
