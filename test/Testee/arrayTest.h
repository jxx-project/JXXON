//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Testee_arrayTest_INCLUDED
#define Testee_arrayTest_INCLUDED

#include "Testee/ArrayTestSuite.h"
#include "JXXON/Vector.h"
#include "JXXON/List.h"
#include "JXXON/Map.h"
#include "JXXON/UnorderedMap.h"
#include "Model/Object.h"
#include <cstdint>
#include <memory>
#include <string>

namespace Testee {

/// Test Arrays.
template<template<typename...> class ArrayType>
int arrayTest(const std::string& arrayType)
{
	bool failed = false;
	
	failed = failed || !Testee::ArrayTestSuite<ArrayType, std::string>(
		arrayType,
		"std::string",
		"[\"a\",\"b\",\"c\"]",
		"[\"a\",\"b\",null]",
		"[{\"value\":\"a\"},{\"value\":\"b\"},{\"value\":\"c\"}]",
		"{\"a\":\"dummy\",\"b\":\"dummy\",\"c\":\"dummy\"}",
		"[\"a\",\"b\",\"\"]").run();

	failed = failed || !Testee::ArrayTestSuite< ArrayType, std::shared_ptr<std::string> >(
		arrayType,
		"std::shared_ptr<std::string>",
		"[\"a\",\"b\",\"c\"]",
		"[\"a\",\"b\",null]",
		"[{\"value\":\"a\"},{\"value\":\"b\"},{\"value\":\"c\"}]",
		"{\"a\":\"dummy\",\"b\":\"dummy\",\"c\":\"dummy\"}",
		"[\"a\",\"b\",null]").run();

	return failed ? 1 : 0;
}

} // namespace Testee

#endif // Testee_arrayTest_INCLUDED
