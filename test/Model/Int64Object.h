//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_Int64Object_INCLUDED
#define Model_Int64Object_INCLUDED

#include "JXXON/Serializable.h"
#include <cstdint>

namespace Model {

struct Int64Object : public JXXON::Serializable {
	Int64Object();
	Int64Object(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::int64_t value;
};

} // namespace Model

#endif // Model_Int64Object_INCLUDED
