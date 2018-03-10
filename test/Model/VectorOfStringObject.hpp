//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_VectorOfStringObject_INCLUDED
#define Model_VectorOfStringObject_INCLUDED

#include "JXXON/Vector.hpp"
#include "JXXON/Serializable.hpp"
#include <string>

namespace Model {

struct VectorOfStringObject : public JXXON::Serializable {
	VectorOfStringObject();
	VectorOfStringObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	JXXON::Vector< std::string > value;
};

} // namespace Model

#endif // Model_VectorOfStringObject_INCLUDED
