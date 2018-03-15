//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_UIntObject_INCLUDED
#define Model_UIntObject_INCLUDED

#include "JXXON/Serializable.h"
#include <string>

namespace Model {

struct UIntObject : public JXXON::Serializable {
	UIntObject();
	UIntObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	unsigned int value;
};

} // namespace Model

#endif // Model_UIntObject_INCLUDED
