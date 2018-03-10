//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_DoubleObject_INCLUDED
#define Model_DoubleObject_INCLUDED

#include "JXXON/Serializable.hpp"

namespace Model {

struct DoubleObject : public JXXON::Serializable {
	DoubleObject();
	DoubleObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	double value;
};

} // namespace Model

#endif // Model_DoubleObject_INCLUDED
