//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Testee_ObjectTestSuite_INCLUDED
#define Testee_ObjectTestSuite_INCLUDED

#include "JXXON/Error.h"
#include "Testee/TestSuite.h"
#include "Model/Object.h"

namespace Testee {

/// Test Objects of type T.
template<typename T>
class ObjectTestSuite : public TestSuite
{
public:

	ObjectTestSuite(
		const std::string& type,
		const std::string& validJSON,
		const std::string& invalidJSON,
		const std::string& expectEmptyJSON = "{}",
		const std::string& altExpectEmptyJSON = "") : TestSuite(type + " objects", {

			TestCase("Valid " + type + " object", [&]
					 {
						 JXXON::Json json(validJSON);
						 Model::Object<T> object(json);
						 TestCase::assert_equal(object.toJson().toString(), validJSON);
					 }),

			TestCase("Empty " + type + " object", [&]
					 {
						 JXXON::Json json("{}");
						 Model::Object<T> object(json);
						 if (altExpectEmptyJSON.empty()) {
							 TestCase::assert_equal(object.toJson().toString(), expectEmptyJSON);
						 } else {
							 TestCase::assert_equal(object.toJson().toString(), expectEmptyJSON, altExpectEmptyJSON);
						 }
					 }),

			TestCase("Invalid " + type + " object", [&]
					 {
						 JXXON::Json json(invalidJSON);
						 TestCase::assert_throw<JXXON::Error>([&]{Model::Object<T> object(json);});
					 })
		})
	{
	}
};

} // namespace Testee

#endif // Testee_ObjectTestSuite_INCLUDED
