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

	failed = !Testee::ArrayTestSuite<ArrayType, std::string>(
		arrayType,
		"std::string",
		"[\"a\",\"b\"]",
		"[\"a\",\"b\",null]",
		"[{\"value\":\"a\"},{\"value\":\"b\"}]",
		"{\"a\":\"dummy\",\"b\":\"dummy\"}",
		"[\"a\",\"b\",\"\"]").run() || failed;

	failed = !Testee::ArrayTestSuite< ArrayType, std::shared_ptr<std::string> >(
		arrayType,
		"std::shared_ptr<std::string>",
		"[\"a\",\"b\"]",
		"[\"a\",\"b\",null]",
		"[{\"value\":\"a\"},{\"value\":\"b\"}]",
		"{\"a\":\"dummy\",\"b\":\"dummy\"}",
		"[\"a\",\"b\",null]").run() || failed;

	failed = !Testee::ArrayTestSuite<ArrayType, int>(
		arrayType,
		"int",
		"[-4711,-4712]",
		"[-4711,-4712,null]",
		"[{\"value\":-4711},{\"value\":-4712}]",
		"{\"a\":-4711,\"b\":-4712}",
		"[-4711,-4712,0]").run() || failed;

	failed = !Testee::ArrayTestSuite< ArrayType, std::shared_ptr<int> >(
		arrayType,
		"std::shared_ptr<int>",
		"[-4711,-4712]",
		"[-4711,-4712,null]",
		"[{\"value\":-4711},{\"value\":-4712}]",
		"{\"a\":-4711,\"b\":-4712}",
		"[-4711,-4712,null]").run() || failed;

	failed = !Testee::ArrayTestSuite<ArrayType, unsigned int>(
		arrayType,
		"unsigned int",
		"[4711,4712]",
		"[4711,4712,null]",
		"[{\"value\":4711},{\"value\":4712}]",
		"{\"a\":4711,\"b\":4712}",
		"[4711,4712,0]").run() || failed;

	failed = !Testee::ArrayTestSuite< ArrayType, std::shared_ptr<unsigned int> >(
		arrayType,
		"std::shared_ptr<unsigned int>",
		"[4711,4712]",
		"[4711,4712,null]",
		"[{\"value\":4711},{\"value\":4712}]",
		"{\"a\":4711,\"b\":4712}",
		"[4711,4712,null]").run() || failed;

	failed = !Testee::ArrayTestSuite<ArrayType, std::int64_t>(
		arrayType,
		"std::int64_t",
		"[-4711471147114711,-4712471247124712]",
		"[-4711471147114711,-4712471247124712,null]",
		"[{\"value\":-4711471147114711},{\"value\":-4712471247124712}]",
		"{\"a\":-4711471147114711,\"b\":-4712471247124712}",
		"[-4711471147114711,-4712471247124712,0]").run() || failed;

	failed = !Testee::ArrayTestSuite< ArrayType, std::shared_ptr<std::int64_t> >(
		arrayType,
		"std::shared_ptr<std::int64_t>",
		"[-4711471147114711,-4712471247124712]",
		"[-4711471147114711,-4712471247124712,null]",
		"[{\"value\":-4711471147114711},{\"value\":-4712471247124712}]",
		"{\"a\":-4711471147114711,\"b\":-4712471247124712}",
		"[-4711471147114711,-4712471247124712,null]").run() || failed;

	failed = !Testee::ArrayTestSuite<ArrayType, std::uint64_t>(
		arrayType,
		"std::uint64_t",
		"[4711471147114711,4712471247124712]",
		"[4711471147114711,4712471247124712,null]",
		"[{\"value\":4711471147114711},{\"value\":4712471247124712}]",
		"{\"a\":4711471147114711,\"b\":4712471247124712}",
		"[4711471147114711,4712471247124712,0]").run() || failed;

	failed = !Testee::ArrayTestSuite< ArrayType, std::shared_ptr<std::uint64_t> >(
		arrayType,
		"std::shared_ptr<std::uint64_t>",
		"[4711471147114711,4712471247124712]",
		"[4711471147114711,4712471247124712,null]",
		"[{\"value\":4711471147114711},{\"value\":4712471247124712}]",
		"{\"a\":4711471147114711,\"b\":4712471247124712}",
		"[4711471147114711,4712471247124712,null]").run() || failed;

	failed = !Testee::ArrayTestSuite<ArrayType, std::intmax_t>(
		arrayType,
		"std::intmax_t",
		"[-4711471147114711,-4712471247124712]",
		"[-4711471147114711,-4712471247124712,null]",
		"[{\"value\":-4711471147114711},{\"value\":-4712471247124712}]",
		"{\"a\":-4711471147114711,\"b\":-4712471247124712}",
		"[-4711471147114711,-4712471247124712,0]").run() || failed;

	failed = !Testee::ArrayTestSuite< ArrayType, std::shared_ptr<std::intmax_t> >(
		arrayType,
		"std::shared_ptr<std::intmax_t>",
		"[-4711471147114711,-4712471247124712]",
		"[-4711471147114711,-4712471247124712,null]",
		"[{\"value\":-4711471147114711},{\"value\":-4712471247124712}]",
		"{\"a\":-4711471147114711,\"b\":-4712471247124712}",
		"[-4711471147114711,-4712471247124712,null]").run() || failed;

	failed = !Testee::ArrayTestSuite<ArrayType, std::uintmax_t>(
		arrayType,
		"std::uintmax_t",
		"[4711471147114711,4712471247124712]",
		"[4711471147114711,4712471247124712,null]",
		"[{\"value\":4711471147114711},{\"value\":4712471247124712}]",
		"{\"a\":4711471147114711,\"b\":4712471247124712}",
		"[4711471147114711,4712471247124712,0]").run() || failed;

	failed = !Testee::ArrayTestSuite< ArrayType, std::shared_ptr<std::uintmax_t> >(
		arrayType,
		"std::shared_ptr<std::uintmax_t>",
		"[4711471147114711,4712471247124712]",
		"[4711471147114711,4712471247124712,null]",
		"[{\"value\":4711471147114711},{\"value\":4712471247124712}]",
		"{\"a\":4711471147114711,\"b\":4712471247124712}",
		"[4711471147114711,4712471247124712,null]").run() || failed;

	failed = !Testee::ArrayTestSuite<ArrayType, float>(
		arrayType,
		"float",
		"[3.25,6.75]",
		"[3.25,6.75,null]",
		"[{\"value\":3.25},{\"value\":6.75}]",
		"{\"a\":3.25,\"b\":6.75}",
		"[3.25,6.75,0.0]",
		"[3.25,6.75,0]").run() || failed;

	failed = !Testee::ArrayTestSuite< ArrayType, std::shared_ptr<float> >(
		arrayType,
		"std::shared_ptr<float>",
		"[3.25,6.75]",
		"[3.25,6.75,null]",
		"[{\"value\":3.25},{\"value\":6.75}]",
		"{\"a\":3.25,\"b\":6.75}",
		"[3.25,6.75,null]").run() || failed;

	failed = !Testee::ArrayTestSuite<ArrayType, double>(
		arrayType,
		"double",
		"[3.25,6.75]",
		"[3.25,6.75,null]",
		"[{\"value\":3.25},{\"value\":6.75}]",
		"{\"a\":3.25,\"b\":6.75}",
		"[3.25,6.75,0.0]",
		"[3.25,6.75,0]").run() || failed;

	failed = !Testee::ArrayTestSuite< ArrayType, std::shared_ptr<double> >(
		arrayType,
		"std::shared_ptr<double>",
		"[3.25,6.75]",
		"[3.25,6.75,null]",
		"[{\"value\":3.25},{\"value\":6.75}]",
		"{\"a\":3.25,\"b\":6.75}",
		"[3.25,6.75,null]").run() || failed;

	failed = !Testee::ArrayTestSuite<ArrayType, bool>(
		arrayType,
		"bool",
		"[true,false]",
		"[true,false,null]",
		"[{\"value\":true},{\"value\":false}]",
		"{\"a\":true,\"b\":false}",
		"[true,false,false]").run() || failed;

	failed = !Testee::ArrayTestSuite< ArrayType, std::shared_ptr<bool> >(
		arrayType,
		"std::shared_ptr<bool>",
		"[true,false]",
		"[true,false,null]",
		"[{\"value\":true},{\"value\":false}]",
		"{\"a\":true,\"b\":false}",
		"[true,false,null]").run() || failed;

	return failed ? 1 : 0;
}

} // namespace Testee

#endif // Testee_arrayTest_INCLUDED
