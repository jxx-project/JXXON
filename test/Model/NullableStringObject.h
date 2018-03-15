//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_NullableStringObject_INCLUDED
#define Model_NullableStringObject_INCLUDED

#include "JXXON/Serializable.h"
#include <string>

namespace Model {

struct NullableStringObject : public JXXON::Serializable {
	NullableStringObject();
	NullableStringObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> value;
};

} // namespace Model

#endif // Model_NullableStringObject_INCLUDED
