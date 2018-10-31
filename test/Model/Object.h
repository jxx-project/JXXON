//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Model_Object_INCLUDED
#define Model_Object_INCLUDED

#include "JXXON/Serializable.h"

namespace Model {

template<typename T>
struct Object : public JXXON::Serializable
{
	typedef T ValueType;

	Object();
	Object(const JXXON::Json& json);
	virtual JXXON::Json toJson() const override;

	ValueType value;
};

} // namespace Model

#endif // Model_Object_INCLUDED
