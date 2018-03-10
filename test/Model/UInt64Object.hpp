//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_UInt64Object_INCLUDED
#define Model_UInt64Object_INCLUDED

#include "JXXON/Serializable.hpp"
#include <cstdint>

namespace Model {

struct UInt64Object : public JXXON::Serializable {
	UInt64Object();
	UInt64Object(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::uint64_t value;
};

} // namespace Model

#endif // Model_UInt64Object_INCLUDED
