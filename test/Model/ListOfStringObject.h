//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_ListOfStringObject_INCLUDED
#define Model_ListOfStringObject_INCLUDED

#include "JXXON/List.h"
#include "JXXON/Serializable.h"
#include <string>

namespace Model {

struct ListOfStringObject : public JXXON::Serializable {
	ListOfStringObject();
	ListOfStringObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	JXXON::List< std::string > value;
};

} // namespace Model

#endif // Model_ListOfStringObject_INCLUDED
