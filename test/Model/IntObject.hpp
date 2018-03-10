//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_IntObject_INCLUDED
#define Model_IntObject_INCLUDED

#include "JXXON/Serializable.hpp"
#include <string>

namespace Model {

struct IntObject : public JXXON::Serializable {
	IntObject();
	IntObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	int value;
};

} // namespace Model

#endif // Model_IntObject_INCLUDED
