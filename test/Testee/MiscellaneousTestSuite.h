//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Testee_MiscellaneousTestSuite_INCLUDED
#define Testee_MiscellaneousTestSuite_INCLUDED

#include "JXXON/Error.h"
#include "Testee/TestSuite.h"
#include "Model/Object.h"
#include <sstream>
#include <string>

namespace Testee {

/// Miscellaneous tests.
class MiscellaneousTestSuite : public TestSuite
{
public:

	MiscellaneousTestSuite() : TestSuite("miscellaneous", {

			TestCase("Read object from stream", [&]
					 {
						 static const std::string JSON_IN(
							 "{\n"
							 "\t\"value\": \"dummy\"\n"
							 "}\n");
						 static const std::string JSON_OUT("{\"value\":\"dummy\"}");
						 std::istringstream in(JSON_IN);
						 JXXON::Json json;
						 in >> json;
						 Model::Object<std::string> object(json);
						 TestCase::assert_equal(object.toJson().toString(), JSON_OUT);
					 }),

			TestCase("Write object to stream", [&]
					 {
						 static const std::string JSON_IN("{\"value\":\"dummy\"}");
						 JXXON::Json json(JSON_IN);
						 Model::Object<std::string> object(json);
						 std::ostringstream out;
						 out << object.toJson();
						 TestCase::assert_equal(out.str(), JSON_IN);
					 }),

			TestCase("Null value", [&]
					 {
						 TestCase::assert_throw<JXXON::Error>([&]{JXXON::Json json("null");});
					 }),

			TestCase("Invalid value", [&]
					 {
						 TestCase::assert_throw<JXXON::Error>([&]{JXXON::Json json("I'm singin' in the rain!");});
					 })
		})
	{
	}
};

} // namespace Testee

#endif // Testee_MiscellaneousTestSuite_INCLUDED
