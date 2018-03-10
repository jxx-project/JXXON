//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_StringObject_INCLUDED
#define Model_StringObject_INCLUDED

#include "JXXON/Serializable.hpp"
#include <string>

namespace Model {

struct StringObject : public JXXON::Serializable {
	StringObject();
	StringObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::string value;
};

} // namespace Model

#endif // Model_StringObject_INCLUDED
