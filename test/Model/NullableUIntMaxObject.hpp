//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_NullableUIntMaxObject_INCLUDED
#define Model_NullableUIntMaxObject_INCLUDED

#include "JXXON/Serializable.hpp"
#include <cstdint>

namespace Model {

struct NullableUIntMaxObject : public JXXON::Serializable {
	NullableUIntMaxObject();
	NullableUIntMaxObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::uintmax_t> value;
};

} // namespace Model

#endif // Model_NullableUIntMaxObject_INCLUDED
