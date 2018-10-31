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

/// Test Arrays.
template<typename ArrayType>
class ArrayTestSuite : public TestSuite
{
public:
	typedef typename ArrayType::DelegateType::size_type SizeType;
	typedef typename ArrayType::DelegateType DelegateType;

	ArrayTestSuite(
		const std::string& arrayType,
		const std::string& type,
		const std::string& validJSON,
		const std::string& validJSONWithNull,
		const std::string& validJSONOfInvalid,
		const std::string& invalidJSON,
		const std::string& expectJSONWithNull,
		const std::string& altExpectJSONWithNull = "") :
		TestSuite(
			"ArrayTestSuite<" + arrayType + "<" + type + ">>",
			{

				TestCase(
					"Valid " + arrayType + " of " + type,
					[&] {
						JXXON::Json json(validJSON);
						ArrayType array(json);
						TestCase::assert_equal(array.toJson().toString(), validJSON);
					}),

				TestCase(
					"Empty " + arrayType + " of " + type,
					[&] {
						static const std::string emptyJSON("[]");
						JXXON::Json json(emptyJSON);
						ArrayType array(json);
						TestCase::assert_equal(array.toJson().toString(), emptyJSON);
					}),

				TestCase(
					"Valid " + arrayType + " of " + type + " with null",
					[&] {
						JXXON::Json json(validJSONWithNull);
						ArrayType array(json);
						if (altExpectJSONWithNull.empty()) {
							TestCase::assert_equal(array.toJson().toString(), expectJSONWithNull);
						} else {
							TestCase::assert_equal(array.toJson().toString(), expectJSONWithNull, altExpectJSONWithNull);
						}
					}),

				TestCase(
					"Valid " + arrayType + " of invalid " + type,
					[&] {
						JXXON::Json json(validJSONOfInvalid);
						TestCase::assert_throw<JXXON::Error>([&] { ArrayType array(json); });
					}),

				TestCase(
					"Invalid " + arrayType + " of " + type,
					[&] {
						JXXON::Json json(invalidJSON);
						TestCase::assert_throw<JXXON::Error>([&] { ArrayType array(json); });
					}),

				TestCase(
					"Copy assignment of " + arrayType + " of " + type,
					[&] {
						const ArrayType array = {typename ArrayType::value_type()};
						ArrayType other;
						other = array;
						TestCase::assert_equal(array.size(), SizeType(1));
						TestCase::assert_equal(other.size(), SizeType(1));
					}),

				TestCase(
					"Move assignment of of " + arrayType + " of " + type,
					[&] {
						ArrayType array = {typename ArrayType::value_type()};
						ArrayType other;
						other = std::move(array);
						TestCase::assert_equal(array.size(), SizeType(0));
						TestCase::assert_equal(other.size(), SizeType(1));
					}),

				TestCase(
					"Delegate type copy assignment of " + arrayType + " of " + type,
					[&] {
						const DelegateType array = {typename ArrayType::value_type()};
						ArrayType other;
						other = array;
						TestCase::assert_equal(array.size(), SizeType(1));
						TestCase::assert_equal(other.size(), SizeType(1));
					}),

				TestCase(
					"Delegate type move assignment of of " + arrayType + " of " + type,
					[&] {
						DelegateType array = {typename ArrayType::value_type()};
						ArrayType other;
						other = std::move(array);
						TestCase::assert_equal(array.size(), SizeType(0));
						TestCase::assert_equal(other.size(), SizeType(1));
					}),

				TestCase(
					"Delegate reference type conversion of " + arrayType + " of " + type,
					[&] {
						ArrayType array = {typename ArrayType::value_type()};
						DelegateType& other = array;
						TestCase::assert_equal(array.size(), SizeType(1));
						TestCase::assert_equal(other.size(), SizeType(1));
					}),

				TestCase(
					"Delegate const reference type conversion of " + arrayType + " of " + type,
					[&] {
						const ArrayType array = {typename ArrayType::value_type()};
						const DelegateType& other = array;
						TestCase::assert_equal(array.size(), SizeType(1));
						TestCase::assert_equal(other.size(), SizeType(1));
					}),

				TestCase(
					"Delegate rvalue reference type conversion of " + arrayType + " of " + type,
					[&] {
						ArrayType array = {typename ArrayType::value_type()};
						DelegateType other = static_cast<DelegateType&&>(array);
						TestCase::assert_equal(array.size(), SizeType(0));
						TestCase::assert_equal(other.size(), SizeType(1));
					})

			})
	{
	}
};

} // namespace Testee

#endif // Testee_ArrayTestSuite_INCLUDED
