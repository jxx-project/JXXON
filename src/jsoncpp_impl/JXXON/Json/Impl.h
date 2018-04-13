//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Json_Impl_INCLUDED
#define JXXON_Json_Impl_INCLUDED

#include <json/json.h>

namespace JXXON {

class Json::Impl
{
public:
	Impl();
	Impl(const ::Json::Value& value);

	::Json::Value value;

	static const ::Json::Value emptyObject;
	static const ::Json::Value emptyArray;

	static ::Json::Value createEmptyObject();
	static ::Json::Value createEmptyArray();
};

} // namespace JXXON

#endif // JXXON_Json_Impl_INCLUDED
