//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_NullableInt64Object_INCLUDED
#define Model_NullableInt64Object_INCLUDED

#include "JXXON/Serializable.hpp"
#include <cstdint>

namespace Model {

struct NullableInt64Object : public JXXON::Serializable {
	NullableInt64Object();
	NullableInt64Object(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::int64_t> value;
};

} // namespace Model

#endif // Model_NullableInt64Object_INCLUDED
