//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Testee_SetTestSuite_INCLUDED
#define Testee_SetTestSuite_INCLUDED

#include "JXXON/Error.h"
#include "Testee/TestSuite.h"

namespace Testee {

/// Test Sets.
template<typename SetType, bool isMultiset>
class SetTestSuite : public TestSuite
{
public:
	typedef typename SetType::DelegateType::size_type SizeType;
	typedef typename SetType::DelegateType DelegateType;

	SetTestSuite(
		const std::string& setType,
		const std::string& type,
		const std::string& jsonObject1,
		const std::string& jsonObject2) :
		TestSuite(
			"SetTestSuite<" + setType + "<" + type + ">>",
			{

				TestCase(
					"[A] " + setType + " of " + type,
					[&] {
						const JXXON::Json json("[" + jsonObject1 + "]");
						SetType set(json);
						TestCase::assert_equal(set.size(), SizeType(1));
					}),

				TestCase(
					"[A,B] " + setType + " of " + type,
					[&] {
						const JXXON::Json json("[" + jsonObject1 + "," + jsonObject2 + "]");
						SetType set(json);
						TestCase::assert_equal(set.size(), SizeType(2));
					}),

				TestCase(
					"[A,B,B] " + setType + " of " + type,
					[&] {
						const JXXON::Json json("[" + jsonObject1 + "," + jsonObject2 + "," + jsonObject2 + "]");
						SetType set(json);
						TestCase::assert_equal(set.size(), SizeType(isMultiset ? 3 : 2));
					}),

				TestCase(
					"[A,B,B,null] " + setType + " of " + type,
					[&] {
						const JXXON::Json json("[" + jsonObject1 + "," + jsonObject2 + "," + jsonObject2 + ",null]");
						SetType set(json);
						TestCase::assert_equal(set.size(), SizeType(isMultiset ? 4 : 3));
					}),

				TestCase(
					"[A,B,B,null,null] " + setType + " of " + type,
					[&] {
						const JXXON::Json json("[" + jsonObject1 + "," + jsonObject2 + "," + jsonObject2 + ",null,null]");
						SetType set(json);
						TestCase::assert_equal(set.size(), SizeType(isMultiset ? 5 : 3));
					})

			})
	{
	}
}; // namespace Testee

} // namespace Testee

#endif // Testee_SetTestSuite_INCLUDED
