//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_IntMaxObject_INCLUDED
#define Model_IntMaxObject_INCLUDED

#include "JXXON/Serializable.hpp"
#include <cstdint>

namespace Model {

struct IntMaxObject : public JXXON::Serializable {
	IntMaxObject();
	IntMaxObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::intmax_t value;
};

} // namespace Model

#endif // Model_IntMaxObject_INCLUDED
