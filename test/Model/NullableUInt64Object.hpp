//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_NullableUInt64Object_INCLUDED
#define Model_NullableUInt64Object_INCLUDED

#include "JXXON/Serializable.hpp"
#include <cstdint>

namespace Model {

struct NullableUInt64Object : public JXXON::Serializable {
	NullableUInt64Object();
	NullableUInt64Object(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::uint64_t> value;
};

} // namespace Model

#endif // Model_NullableUInt64Object_INCLUDED
