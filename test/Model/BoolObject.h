//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_BoolObject_INCLUDED
#define Model_BoolObject_INCLUDED

#include "JXXON/Serializable.h"

namespace Model {

struct BoolObject : public JXXON::Serializable {
	BoolObject();
	BoolObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	bool value;
};

} // namespace Model

#endif // Model_BoolObject_INCLUDED
