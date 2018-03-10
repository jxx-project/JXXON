//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_NullableListOfStringObject_INCLUDED
#define Model_NullableListOfStringObject_INCLUDED

#include "JXXON/List.hpp"
#include "JXXON/Serializable.hpp"
#include <string>

namespace Model {

struct NullableListOfStringObject : public JXXON::Serializable {
	NullableListOfStringObject();
	NullableListOfStringObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr< JXXON::List< std::shared_ptr<std::string> > > value;
};

} // namespace Model

#endif // Model_NullableListOfStringObject_INCLUDED
