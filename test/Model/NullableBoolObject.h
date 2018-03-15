//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_NullableBoolObject_INCLUDED
#define Model_NullableBoolObject_INCLUDED

#include "JXXON/Serializable.h"

namespace Model {

struct NullableBoolObject : public JXXON::Serializable {
	NullableBoolObject();
	NullableBoolObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<bool> value;
};

} // namespace Model

#endif // Model_NullableBoolObject_INCLUDED
