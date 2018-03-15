//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_FloatObject_INCLUDED
#define Model_FloatObject_INCLUDED

#include "JXXON/Serializable.h"

namespace Model {

struct FloatObject : public JXXON::Serializable {
	FloatObject();
	FloatObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	float value;
};

} // namespace Model

#endif // Model_FloatObject_INCLUDED
