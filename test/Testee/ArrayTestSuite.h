//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Testee_ArrayTestSuite_INCLUDED
#define Testee_ArrayTestSuite_INCLUDED

#include "JXXON/Error.h"
#include "Testee/TestSuite.h"

namespace Testee {

/// Test Arrays of type T.
template<template<typename...> class ArrayType, typename T>
class ArrayTestSuite : public TestSuite
{
public:

	ArrayTestSuite(
		const std::string& arrayType,
		const std::string& type,
		const std::string& validJSON,
		const std::string& validJSONWithNull,
		const std::string& validJSONOfInvalid,
		const std::string& invalidJSON,
		const std::string& expectJSONWithNull,
		const std::string& altExpectJSONWithNull = "") : TestSuite(arrayType + "< " + type + " >", {

			TestCase("Valid " + arrayType + " of " + type, [&]
					 {
						 JXXON::Json json(validJSON);
						 ArrayType<T> array(json);
						 TestCase::assert_equal(array.toJson().toString(), validJSON);
					 }),

			TestCase("Empty " + arrayType + " of " + type, [&]
					 {
						 static const std::string emptyJSON("[]");
						 JXXON::Json json(emptyJSON);
						 ArrayType<T> array(json);
						 TestCase::assert_equal(array.toJson().toString(), emptyJSON);
					 }),

			TestCase("Valid " + arrayType + " of " + type + " with null", [&]
					 {
						 JXXON::Json json(validJSONWithNull);
						 ArrayType<T> array(json);
						 if (altExpectJSONWithNull.empty()) {
							 TestCase::assert_equal(array.toJson().toString(), expectJSONWithNull);
						 } else {
							 TestCase::assert_equal(array.toJson().toString(), expectJSONWithNull, altExpectJSONWithNull);
						 }
					 }),

			TestCase("Valid " + arrayType + " of invalid " + type, [&]
					 {
						 JXXON::Json json(validJSONOfInvalid);
						 TestCase::assert_throw<JXXON::Error>([&]{ArrayType<T> array(json);});
					 }),

			TestCase("Invalid " + arrayType + " of " + type, [&]
					 {
						 JXXON::Json json(invalidJSON);
						 TestCase::assert_throw<JXXON::Error>([&]{ArrayType<T> array(json);});
					 }),

			TestCase("Delegate reference type conversion of " + arrayType + " of " + type, [&]
					 {
						 ArrayType<T> array({T()});
						 typename ArrayType<T>::DelegateType& other = array;
						 TestCase::assert_equal(array.size(), typename ArrayType<T>::size_type(1));
						 TestCase::assert_equal(other.size(), typename ArrayType<T>::DelegateType::size_type(1));
					 }),

			TestCase("Delegate const reference type conversion of " + arrayType + " of " + type, [&]
					 {
						 const ArrayType<T> array({T()});
						 const typename ArrayType<T>::DelegateType& other = array;
						 TestCase::assert_equal(array.size(), typename ArrayType<T>::size_type(1));
						 TestCase::assert_equal(other.size(), typename ArrayType<T>::DelegateType::size_type(1));
					 }),

			TestCase("Delegate rvalue reference type conversion of " + arrayType + " of " + type, [&]
					 {
						 ArrayType<T> array({T()});
						 typename ArrayType<T>::DelegateType other = static_cast<typename ArrayType<T>::DelegateType&&>(array);
						 TestCase::assert_equal(array.size(), typename ArrayType<T>::size_type(0));
						 TestCase::assert_equal(other.size(), typename ArrayType<T>::DelegateType::size_type(1));
					 })
		})
	{
	}
};

} // namespace Testee

#endif // Testee_ArrayTestSuite_INCLUDED
