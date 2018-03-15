//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_NullableIntMaxObject_INCLUDED
#define Model_NullableIntMaxObject_INCLUDED

#include "JXXON/Serializable.h"
#include <cstdint>

namespace Model {

struct NullableIntMaxObject : public JXXON::Serializable {
	NullableIntMaxObject();
	NullableIntMaxObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::intmax_t> value;
};

} // namespace Model

#endif // Model_NullableIntMaxObject_INCLUDED
