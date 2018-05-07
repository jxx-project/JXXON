//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Testee_MapTestSuite_INCLUDED
#define Testee_MapTestSuite_INCLUDED

#include "JXXON/Error.h"
#include "Testee/TestSuite.h"

namespace Testee {

/// Test Maps of type T.
template<template<typename...> class MapType, typename T>
class MapTestSuite : public TestSuite
{
public:
	typedef typename MapType<T>::DelegateType::size_type SizeType;
	typedef typename MapType<T>::DelegateType DelegateType;

	MapTestSuite(
		const std::string& mapType,
		const std::string& type,
		const std::string& validJSON,
		const std::string& validJSONWithNull,
		const std::string& validJSONOfInvalid,
		const std::string& invalidJSON,
		const std::string& expectJSONWithNull,
		const std::string& altExpectJSONWithNull = "") : TestSuite(mapType + "< " + type + " >", {

			TestCase("Valid " + mapType + " of " + type, [&]
					 {
						 JXXON::Json json(validJSON);
						 MapType<T> map(json);
						 TestCase::assert_equal(map.toJson().toString(), validJSON);
					 }),

			TestCase("Empty " + mapType + " of " + type, [&]
					 {
						 static const std::string emptyJSON("{}");
						 JXXON::Json json(emptyJSON);
						 MapType<T> map(json);
						 TestCase::assert_equal(map.toJson().toString(), emptyJSON);
					 }),

			TestCase("Valid " + mapType + " of " + type + " with null", [&]
					 {
						 JXXON::Json json(validJSONWithNull);
						 MapType<T> map(json);
						 if (altExpectJSONWithNull.empty()) {
							 TestCase::assert_equal(map.toJson().toString(), expectJSONWithNull);
						 } else {
							 TestCase::assert_equal(map.toJson().toString(), expectJSONWithNull, altExpectJSONWithNull);
						 }
					 }),

			TestCase("Valid " + mapType + " of invalid " + type, [&]
					 {
						 JXXON::Json json(validJSONOfInvalid);
						 TestCase::assert_throw<JXXON::Error>([&]{MapType<T> map(json);});
					 }),

			TestCase("Invalid " + mapType + " of " + type, [&]
					 {
						 JXXON::Json json(invalidJSON);
						 TestCase::assert_throw<JXXON::Error>([&]{MapType<T> map(json);});
					 }),

			TestCase("Copy assignment of " + mapType + " of " + type, [&]
					 {
						 const MapType<T> map = {std::make_pair(std::string(""), T())};
						 MapType<T> other;
						 other = map;
						 TestCase::assert_equal(map.size(), SizeType(1));
						 TestCase::assert_equal(other.size(), SizeType(1));
					 }),

			TestCase("Move assignment of " + mapType + " of " + type, [&]
					 {
						 MapType<T> map = {std::make_pair(std::string(""), T())};
						 MapType<T> other;
						 other = std::move(map);
						 TestCase::assert_equal(map.size(), SizeType(0));
						 TestCase::assert_equal(other.size(), SizeType(1));
					 }),

			TestCase("Delegate type copy assignment of " + mapType + " of " + type, [&]
					 {
						 const DelegateType map = {std::make_pair(std::string(""), T())};
						 MapType<T> other;
						 other = map;
						 TestCase::assert_equal(map.size(), SizeType(1));
						 TestCase::assert_equal(other.size(), SizeType(1));
					 }),

			TestCase("Delegate type move assignment of " + mapType + " of " + type, [&]
					 {
						 DelegateType map = {std::make_pair(std::string(""), T())};
						 MapType<T> other;
						 other = std::move(map);
						 TestCase::assert_equal(map.size(), SizeType(0));
						 TestCase::assert_equal(other.size(), SizeType(1));
					 }),

			TestCase("Delegate reference type conversion of " + mapType + " of " + type, [&]
					 {
						 MapType<T> map = {std::make_pair(std::string(""), T())};
						 DelegateType& other = map;
						 TestCase::assert_equal(map.size(), SizeType(1));
						 TestCase::assert_equal(other.size(), SizeType(1));
					 }),

			TestCase("Delegate const reference type conversion of " + mapType + " of " + type, [&]
					 {
						 const MapType<T> map = {std::make_pair(std::string(""), T())};
						 const DelegateType& other = map;
						 TestCase::assert_equal(map.size(), SizeType(1));
						 TestCase::assert_equal(other.size(), SizeType(1));
					 }),

			TestCase("Delegate rvalue reference type conversion of " + mapType + " of " + type, [&]
					 {
						 MapType<T> map = {std::make_pair(std::string(""), T())};
						 DelegateType other = static_cast<DelegateType&&>(map);
						 TestCase::assert_equal(map.size(), SizeType(0));
						 TestCase::assert_equal(other.size(), SizeType(1));
					 })
		})
	{
	}
};

} // namespace Testee

#endif // Testee_MapTestSuite_INCLUDED
