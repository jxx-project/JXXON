//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_NullableDoubleObject_INCLUDED
#define Model_NullableDoubleObject_INCLUDED

#include "JXXON/Serializable.hpp"

namespace Model {

struct NullableDoubleObject : public JXXON::Serializable {
	NullableDoubleObject();
	NullableDoubleObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<double> value;
};

} // namespace Model

#endif // Model_NullableDoubleObject_INCLUDED
