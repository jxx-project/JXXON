//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Model_NullableVectorOfStringObject_INCLUDED
#define Model_NullableVectorOfStringObject_INCLUDED

#include "JXXON/Vector.hpp"
#include "JXXON/Serializable.hpp"
#include <string>

namespace Model {

struct NullableVectorOfStringObject : public JXXON::Serializable {
	NullableVectorOfStringObject();
	NullableVectorOfStringObject(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr< JXXON::Vector< std::shared_ptr<std::string> > > value;
};

} // namespace Model

#endif // Model_NullableVectorOfStringObject_INCLUDED
