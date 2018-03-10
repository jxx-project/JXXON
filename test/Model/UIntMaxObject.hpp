//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_UIntMaxObject_INCLUDED
#define Model_UIntMaxObject_INCLUDED

#include "JXXON/Serializable.hpp"
#include <cstdint>

namespace Model {

struct UIntMaxObject : public JXXON::Serializable {
	UIntMaxObject();
	UIntMaxObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::uintmax_t value;
};

} // namespace Model

#endif // Model_UIntMaxObject_INCLUDED
