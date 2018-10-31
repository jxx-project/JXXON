//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Testee_arrayTest_INCLUDED
#define Testee_arrayTest_INCLUDED

#include "JXXON/List.h"
#include "JXXON/Map.h"
#include "JXXON/UnorderedMap.h"
#include "JXXON/Vector.h"
#include "Model/Object.h"
#include "Testee/ArrayTestSuite.h"
#include <cstdint>
#include <memory>
#include <string>

namespace Testee {

/// Test Arrays.
template<template<typename...> class ArrayType>
int arrayTest(const std::string& arrayType)
{
	bool failed = false;

	failed = !Testee::ArrayTestSuite<ArrayType<std::string>>(
				  arrayType,
				  "std::string",
				  "[\"a\",\"b\"]",
				  "[\"a\",\"b\",null]",
				  "[{\"value\":\"a\"},{\"value\":\"b\"}]",
				  "{\"a\":\"dummy\",\"b\":\"dummy\"}",
				  "[\"a\",\"b\",\"\"]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<std::string>>>(
				  arrayType,
				  "std::shared_ptr<std::string>",
				  "[\"a\",\"b\"]",
				  "[\"a\",\"b\",null]",
				  "[{\"value\":\"a\"},{\"value\":\"b\"}]",
				  "{\"a\":\"dummy\",\"b\":\"dummy\"}",
				  "[\"a\",\"b\",null]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<int>>(
				  arrayType,
				  "int",
				  "[-4711,-4712]",
				  "[-4711,-4712,null]",
				  "[{\"value\":-4711},{\"value\":-4712}]",
				  "{\"a\":-4711,\"b\":-4712}",
				  "[-4711,-4712,0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<int>>>(
				  arrayType,
				  "std::shared_ptr<int>",
				  "[-4711,-4712]",
				  "[-4711,-4712,null]",
				  "[{\"value\":-4711},{\"value\":-4712}]",
				  "{\"a\":-4711,\"b\":-4712}",
				  "[-4711,-4712,null]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<unsigned int>>(
				  arrayType,
				  "unsigned int",
				  "[4711,4712]",
				  "[4711,4712,null]",
				  "[{\"value\":4711},{\"value\":4712}]",
				  "{\"a\":4711,\"b\":4712}",
				  "[4711,4712,0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<unsigned int>>>(
				  arrayType,
				  "std::shared_ptr<unsigned int>",
				  "[4711,4712]",
				  "[4711,4712,null]",
				  "[{\"value\":4711},{\"value\":4712}]",
				  "{\"a\":4711,\"b\":4712}",
				  "[4711,4712,null]")
				  .run() ||
			 failed;

#if (_SIZEOF_INT8_T + 0)
	failed = !Testee::ArrayTestSuite<ArrayType<std::int8_t>>(
				  arrayType,
				  "std::int8_t",
				  "[-47,-48]",
				  "[-47,-48,null]",
				  "[{\"value\":-47},{\"value\":-47}]",
				  "{\"a\":-47,\"b\":-48}",
				  "[-47,-48,0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<std::int8_t>>>(
				  arrayType,
				  "std::shared_ptr<std::int8_t>",
				  "[-47,-48]",
				  "[-47,-48,null]",
				  "[{\"value\":-47},{\"value\":-48}]",
				  "{\"a\":-47,\"b\":-48}",
				  "[-47,-48,null]")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_UINT8_T + 0)
	failed = !Testee::ArrayTestSuite<ArrayType<std::uint8_t>>(
				  arrayType,
				  "std::uint8_t",
				  "[47,48]",
				  "[47,48,null]",
				  "[{\"value\":47},{\"value\":48}]",
				  "{\"a\":47,\"b\":48}",
				  "[47,48,0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<std::uint8_t>>>(
				  arrayType,
				  "std::shared_ptr<std::uint8_t>",
				  "[47,48]",
				  "[47,48,null]",
				  "[{\"value\":47},{\"value\":48}]",
				  "{\"a\":47,\"b\":48}",
				  "[47,48,null]")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_INT16_T + 0)
	failed = !Testee::ArrayTestSuite<ArrayType<std::int16_t>>(
				  arrayType,
				  "std::int16_t",
				  "[-4711,-4712]",
				  "[-4711,-4712,null]",
				  "[{\"value\":-4711},{\"value\":-4712}]",
				  "{\"a\":-4711,\"b\":-4712}",
				  "[-4711,-4712,0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<std::int16_t>>>(
				  arrayType,
				  "std::shared_ptr<std::int16_t>",
				  "[-4711,-4712]",
				  "[-4711,-4712,null]",
				  "[{\"value\":-4711},{\"value\":-4712}]",
				  "{\"a\":-4711,\"b\":-4712}",
				  "[-4711,-4712,null]")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_UINT16_T + 0)
	failed = !Testee::ArrayTestSuite<ArrayType<std::uint16_t>>(
				  arrayType,
				  "std::uint16_t",
				  "[4711,4712]",
				  "[4711,4712,null]",
				  "[{\"value\":4711},{\"value\":4712}]",
				  "{\"a\":4711,\"b\":4712}",
				  "[4711,4712,0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<std::uint16_t>>>(
				  arrayType,
				  "std::shared_ptr<std::uint16_t>",
				  "[4711,4712]",
				  "[4711,4712,null]",
				  "[{\"value\":4711},{\"value\":4712}]",
				  "{\"a\":4711,\"b\":4712}",
				  "[4711,4712,null]")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_INT32_T + 0)
	failed = !Testee::ArrayTestSuite<ArrayType<std::int32_t>>(
				  arrayType,
				  "std::int32_t",
				  "[-47114711,-47124712]",
				  "[-47114711,-47124712,null]",
				  "[{\"value\":-47114711},{\"value\":-47124712}]",
				  "{\"a\":-47114711,\"b\":-47124712}",
				  "[-47114711,-47124712,0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<std::int32_t>>>(
				  arrayType,
				  "std::shared_ptr<std::int32_t>",
				  "[-47114711,-47124712]",
				  "[-47114711,-47124712,null]",
				  "[{\"value\":-47114711},{\"value\":-47124712}]",
				  "{\"a\":-47114711,\"b\":-47124712}",
				  "[-47114711,-47124712,null]")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_UINT32_T + 0)
	failed = !Testee::ArrayTestSuite<ArrayType<std::uint32_t>>(
				  arrayType,
				  "std::uint32_t",
				  "[47114711,47124712]",
				  "[47114711,47124712,null]",
				  "[{\"value\":47114711},{\"value\":47124712}]",
				  "{\"a\":47114711,\"b\":47124712}",
				  "[47114711,47124712,0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<std::uint32_t>>>(
				  arrayType,
				  "std::shared_ptr<std::uint32_t>",
				  "[47114711,47124712]",
				  "[47114711,47124712,null]",
				  "[{\"value\":47114711},{\"value\":47124712}]",
				  "{\"a\":47114711,\"b\":47124712}",
				  "[47114711,47124712,null]")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_INT64_T + 0)
	failed = !Testee::ArrayTestSuite<ArrayType<std::int64_t>>(
				  arrayType,
				  "std::int64_t",
				  "[-4711471147114711,-4712471247124712]",
				  "[-4711471147114711,-4712471247124712,null]",
				  "[{\"value\":-4711471147114711},{\"value\":-4712471247124712}]",
				  "{\"a\":-4711471147114711,\"b\":-4712471247124712}",
				  "[-4711471147114711,-4712471247124712,0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<std::int64_t>>>(
				  arrayType,
				  "std::shared_ptr<std::int64_t>",
				  "[-4711471147114711,-4712471247124712]",
				  "[-4711471147114711,-4712471247124712,null]",
				  "[{\"value\":-4711471147114711},{\"value\":-4712471247124712}]",
				  "{\"a\":-4711471147114711,\"b\":-4712471247124712}",
				  "[-4711471147114711,-4712471247124712,null]")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_UINT64_T + 0)
	failed = !Testee::ArrayTestSuite<ArrayType<std::uint64_t>>(
				  arrayType,
				  "std::uint64_t",
				  "[4711471147114711,4712471247124712]",
				  "[4711471147114711,4712471247124712,null]",
				  "[{\"value\":4711471147114711},{\"value\":4712471247124712}]",
				  "{\"a\":4711471147114711,\"b\":4712471247124712}",
				  "[4711471147114711,4712471247124712,0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<std::uint64_t>>>(
				  arrayType,
				  "std::shared_ptr<std::uint64_t>",
				  "[4711471147114711,4712471247124712]",
				  "[4711471147114711,4712471247124712,null]",
				  "[{\"value\":4711471147114711},{\"value\":4712471247124712}]",
				  "{\"a\":4711471147114711,\"b\":4712471247124712}",
				  "[4711471147114711,4712471247124712,null]")
				  .run() ||
			 failed;
#endif

	failed = !Testee::ArrayTestSuite<ArrayType<std::intmax_t>>(
				  arrayType,
				  "std::intmax_t",
				  "[-4711471147114711,-4712471247124712]",
				  "[-4711471147114711,-4712471247124712,null]",
				  "[{\"value\":-4711471147114711},{\"value\":-4712471247124712}]",
				  "{\"a\":-4711471147114711,\"b\":-4712471247124712}",
				  "[-4711471147114711,-4712471247124712,0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<std::intmax_t>>>(
				  arrayType,
				  "std::shared_ptr<std::intmax_t>",
				  "[-4711471147114711,-4712471247124712]",
				  "[-4711471147114711,-4712471247124712,null]",
				  "[{\"value\":-4711471147114711},{\"value\":-4712471247124712}]",
				  "{\"a\":-4711471147114711,\"b\":-4712471247124712}",
				  "[-4711471147114711,-4712471247124712,null]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::uintmax_t>>(
				  arrayType,
				  "std::uintmax_t",
				  "[4711471147114711,4712471247124712]",
				  "[4711471147114711,4712471247124712,null]",
				  "[{\"value\":4711471147114711},{\"value\":4712471247124712}]",
				  "{\"a\":4711471147114711,\"b\":4712471247124712}",
				  "[4711471147114711,4712471247124712,0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<std::uintmax_t>>>(
				  arrayType,
				  "std::shared_ptr<std::uintmax_t>",
				  "[4711471147114711,4712471247124712]",
				  "[4711471147114711,4712471247124712,null]",
				  "[{\"value\":4711471147114711},{\"value\":4712471247124712}]",
				  "{\"a\":4711471147114711,\"b\":4712471247124712}",
				  "[4711471147114711,4712471247124712,null]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<float>>(
				  arrayType,
				  "float",
				  "[3.25,6.75]",
				  "[3.25,6.75,null]",
				  "[{\"value\":3.25},{\"value\":6.75}]",
				  "{\"a\":3.25,\"b\":6.75}",
				  "[3.25,6.75,0.0]",
				  "[3.25,6.75,0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<float>>>(
				  arrayType,
				  "std::shared_ptr<float>",
				  "[3.25,6.75]",
				  "[3.25,6.75,null]",
				  "[{\"value\":3.25},{\"value\":6.75}]",
				  "{\"a\":3.25,\"b\":6.75}",
				  "[3.25,6.75,null]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<double>>(
				  arrayType,
				  "double",
				  "[3.25,6.75]",
				  "[3.25,6.75,null]",
				  "[{\"value\":3.25},{\"value\":6.75}]",
				  "{\"a\":3.25,\"b\":6.75}",
				  "[3.25,6.75,0.0]",
				  "[3.25,6.75,0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<double>>>(
				  arrayType,
				  "std::shared_ptr<double>",
				  "[3.25,6.75]",
				  "[3.25,6.75,null]",
				  "[{\"value\":3.25},{\"value\":6.75}]",
				  "{\"a\":3.25,\"b\":6.75}",
				  "[3.25,6.75,null]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<bool>>(
				  arrayType,
				  "bool",
				  "[true,false]",
				  "[true,false,null]",
				  "[{\"value\":true},{\"value\":false}]",
				  "{\"a\":true,\"b\":false}",
				  "[true,false,false]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<bool>>>(
				  arrayType,
				  "std::shared_ptr<bool>",
				  "[true,false]",
				  "[true,false,null]",
				  "[{\"value\":true},{\"value\":false}]",
				  "{\"a\":true,\"b\":false}",
				  "[true,false,null]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<Model::Object<std::string>>>(
				  arrayType,
				  "Model::Object<std::string>",
				  "[{\"value\":\"a\"},{\"value\":\"b\"}]",
				  "[{\"value\":\"a\"},{\"value\":\"b\"},null]",
				  "[\"a\",\"b\"]",
				  "{\"a\":\"dummy\",\"b\":\"dummy\"}",
				  "[{\"value\":\"a\"},{\"value\":\"b\"},{\"value\":\"\"}]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<Model::Object<std::string>>>>(
				  arrayType,
				  "std::shared_ptr<Model::Object<std::string>>",
				  "[{\"value\":\"a\"},{\"value\":\"b\"}]",
				  "[{\"value\":\"a\"},{\"value\":\"b\"},null]",
				  "[\"a\",\"b\"]",
				  "{\"a\":\"dummy\",\"b\":\"dummy\"}",
				  "[{\"value\":\"a\"},{\"value\":\"b\"},null]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<JXXON::Vector<std::string>>>(
				  arrayType,
				  "JXXON::Vector<std::string>",
				  "[[\"a\",\"b\"],[\"c\",\"d\"]]",
				  "[[\"a\",\"b\"],[\"c\",\"d\"],null]",
				  "[\"a\",\"b\"]",
				  "{\"a\":\"dummy\",\"b\":\"dummy\"}",
				  "[[\"a\",\"b\"],[\"c\",\"d\"],[]]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<JXXON::Vector<std::string>>>>(
				  arrayType,
				  "std::shared_ptr<JXXON::Vector<std::string>>",
				  "[[\"a\",\"b\"],[\"c\",\"d\"]]",
				  "[[\"a\",\"b\"],[\"c\",\"d\"],null]",
				  "[\"a\",\"b\"]",
				  "{\"a\":\"dummy\",\"b\":\"dummy\"}",
				  "[[\"a\",\"b\"],[\"c\",\"d\"],null]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<JXXON::List<std::string>>>(
				  arrayType,
				  "JXXON::List<std::string>",
				  "[[\"a\",\"b\"],[\"c\",\"d\"]]",
				  "[[\"a\",\"b\"],[\"c\",\"d\"],null]",
				  "[\"a\",\"b\"]",
				  "{\"a\":\"dummy\",\"b\":\"dummy\"}",
				  "[[\"a\",\"b\"],[\"c\",\"d\"],[]]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<JXXON::List<std::string>>>>(
				  arrayType,
				  "std::shared_ptr<JXXON::List<std::string>>",
				  "[[\"a\",\"b\"],[\"c\",\"d\"]]",
				  "[[\"a\",\"b\"],[\"c\",\"d\"],null]",
				  "[\"a\",\"b\"]",
				  "{\"a\":\"dummy\",\"b\":\"dummy\"}",
				  "[[\"a\",\"b\"],[\"c\",\"d\"],null]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<JXXON::Map<std::string>>>(
				  arrayType,
				  "JXXON::Map<std::string>",
				  "[{\"value\":\"a\"},{\"value\":\"b\"}]",
				  "[{\"value\":\"a\"},{\"value\":\"b\"},null]",
				  "[\"a\",\"b\"]",
				  "{\"a\":\"dummy\",\"b\":\"dummy\"}",
				  "[{\"value\":\"a\"},{\"value\":\"b\"},{}]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<JXXON::Map<std::string>>>>(
				  arrayType,
				  "std::shared_ptr<JXXON::Map<std::string>>",
				  "[{\"value\":\"a\"},{\"value\":\"b\"}]",
				  "[{\"value\":\"a\"},{\"value\":\"b\"},null]",
				  "[\"a\",\"b\"]",
				  "{\"a\":\"dummy\",\"b\":\"dummy\"}",
				  "[{\"value\":\"a\"},{\"value\":\"b\"},null]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<JXXON::UnorderedMap<std::string>>>(
				  arrayType,
				  "JXXON::UnorderedMap<std::string>",
				  "[{\"value\":\"a\"},{\"value\":\"b\"}]",
				  "[{\"value\":\"a\"},{\"value\":\"b\"},null]",
				  "[\"a\",\"b\"]",
				  "{\"a\":\"dummy\",\"b\":\"dummy\"}",
				  "[{\"value\":\"a\"},{\"value\":\"b\"},{}]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<ArrayType<std::shared_ptr<JXXON::UnorderedMap<std::string>>>>(
				  arrayType,
				  "std::shared_ptr<JXXON::UnorderedMap<std::string>>",
				  "[{\"value\":\"a\"},{\"value\":\"b\"}]",
				  "[{\"value\":\"a\"},{\"value\":\"b\"},null]",
				  "[\"a\",\"b\"]",
				  "{\"a\":\"dummy\",\"b\":\"dummy\"}",
				  "[{\"value\":\"a\"},{\"value\":\"b\"},null]")
				  .run() ||
			 failed;

	return failed ? 1 : 0;
}

} // namespace Testee

#endif // Testee_arrayTest_INCLUDED
