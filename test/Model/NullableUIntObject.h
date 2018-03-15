//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_NullableUIntObject_INCLUDED
#define Model_NullableUIntObject_INCLUDED

#include "JXXON/Serializable.h"
#include <string>

namespace Model {

struct NullableUIntObject : public JXXON::Serializable {
	NullableUIntObject();
	NullableUIntObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<unsigned int> value;
};

} // namespace Model

#endif // Model_NullableUIntObject_INCLUDED
