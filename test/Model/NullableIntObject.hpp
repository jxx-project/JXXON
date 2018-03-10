//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_NullableIntObject_INCLUDED
#define Model_NullableIntObject_INCLUDED

#include "JXXON/Serializable.hpp"
#include <string>

namespace Model {

struct NullableIntObject : public JXXON::Serializable {
	NullableIntObject();
	NullableIntObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<int> value;
};

} // namespace Model

#endif // Model_NullableIntObject_INCLUDED
