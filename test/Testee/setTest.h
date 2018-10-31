//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Testee_arrayTest_INCLUDED
#define Testee_arrayTest_INCLUDED

#include "JXXON/IsSharedPtr.h"
#include "Model/Object.h"
#include "Testee/ArrayTestSuite.h"
#include "Testee/SetTestSuite.h"
#include <cstdint>
#include <memory>
#include <string>

namespace Testee {

template<template<typename...> class SetType, bool isUnordered, typename Key, typename Enable = void>
struct SetOfObject;

template<template<typename...> class SetType, bool isUnordered, typename Key>
struct SetOfObject<SetType, isUnordered, Key, typename std::enable_if<!isUnordered>::type>
{
	template<typename T, typename Enable = void>
	struct Less;

	template<typename T>
	struct Less<T, typename std::enable_if<!JXXON::IsSharedPtr<T>::value>::type>
	{
		bool operator()(const T& lhs, const T& rhs) const
		{
			return std::less<typename T::ValueType>()(lhs.value, rhs.value);
		}
	};

	template<typename T>
	struct Less<T, typename std::enable_if<JXXON::IsSharedPtr<T>::value>::type>
	{
		bool operator()(const T& lhs, const T& rhs) const
		{
			return lhs && rhs ? std::less<typename T::element_type::ValueType>()(lhs->value, rhs->value) : lhs || rhs;
		}
	};

	typedef SetType<Key, Less<Key>> Type;
};

template<template<typename...> class SetType, bool isUnordered, typename Key>
struct SetOfObject<SetType, isUnordered, Key, typename std::enable_if<isUnordered>::type>
{
	template<typename T, typename Enable = void>
	struct Hash;

	template<typename T>
	struct Hash<T, typename std::enable_if<!JXXON::IsSharedPtr<T>::value>::type>
	{
		std::size_t operator()(const T& arg) const
		{
			return std::hash<typename T::ValueType>()(arg.value);
		}
	};

	template<typename T>
	struct Hash<T, typename std::enable_if<JXXON::IsSharedPtr<T>::value>::type>
	{
		std::size_t operator()(const T& ptr) const
		{
			return ptr ? std::hash<typename T::element_type::ValueType>()(ptr->value) : 0;
		}
	};

	template<typename T, typename Enable = void>
	struct EqualTo;

	template<typename T>
	struct EqualTo<T, typename std::enable_if<!JXXON::IsSharedPtr<T>::value>::type>
	{
		bool operator()(const T& lhs, const T& rhs) const
		{
			return std::equal_to<typename T::ValueType>()(lhs.value, rhs.value);
		}
	};

	template<typename T>
	struct EqualTo<T, typename std::enable_if<JXXON::IsSharedPtr<T>::value>::type>
	{
		bool operator()(const T& lhs, const T& rhs) const
		{
			return lhs && rhs ? std::equal_to<typename T::element_type::ValueType>()(lhs->value, rhs->value) : !lhs && !rhs;
		}
	};

	typedef SetType<Key, Hash<Key>, EqualTo<Key>> Type;
};

/// Test Sets.
template<template<typename...> class SetType, bool isUnordered, bool isMultiset>
int setTest(const std::string& setType)
{
	bool failed = false;

	failed = !Testee::ArrayTestSuite<SetType<std::string>>(
				  setType, "std::string", "[\"a\"]", "[null]", "[{\"value\":\"a\"}]", "{\"a\":\"dummy\"}", "[\"\"]")
				  .run() ||
			 failed;

	failed =
		!Testee::ArrayTestSuite<SetType<std::shared_ptr<std::string>>>(
			 setType, "std::shared_ptr<std::string>", "[\"a\"]", "[null]", "[{\"value\":\"a\"}]", "{\"a\":\"dummy\"}", "[null]")
			 .run() ||
		failed;

	failed =
		!Testee::ArrayTestSuite<SetType<int>>(setType, "int", "[-4711]", "[null]", "[{\"value\":-4711}]", "{\"a\":-4711}", "[0]")
			 .run() ||
		failed;

	failed = !Testee::ArrayTestSuite<SetType<std::shared_ptr<int>>>(
				  setType, "std::shared_ptr<int>", "[-4711]", "[null]", "[{\"value\":-4711}]", "{\"a\":-4711}", "[null]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<unsigned int>>(
				  setType, "unsigned int", "[4711]", "[null]", "[{\"value\":4711}]", "{\"a\":4711}", "[0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<std::shared_ptr<unsigned int>>>(
				  setType, "std::shared_ptr<unsigned int>", "[4711]", "[null]", "[{\"value\":4711}]", "{\"a\":4711}", "[null]")
				  .run() ||
			 failed;

#if (_SIZEOF_INT8_T + 0)
	failed = !Testee::ArrayTestSuite<SetType<std::int8_t>>(
				  setType, "std::int8_t", "[-47]", "[null]", "[{\"value\":-47}]", "{\"a\":-47}", "[0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<std::shared_ptr<std::int8_t>>>(
				  setType, "std::shared_ptr<std::int8_t>", "[-47]", "[null]", "[{\"value\":-47}]", "{\"a\":-47}", "[null]")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_UINT8_T + 0)
	failed = !Testee::ArrayTestSuite<SetType<std::uint8_t>>(
				  setType, "std::uint8_t", "[47]", "[null]", "[{\"value\":47}]", "{\"a\":47}", "[0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<std::shared_ptr<std::uint8_t>>>(
				  setType, "std::shared_ptr<std::uint8_t>", "[47]", "[null]", "[{\"value\":47}]", "{\"a\":47}", "[null]")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_INT16_T + 0)
	failed = !Testee::ArrayTestSuite<SetType<std::int16_t>>(
				  setType, "std::int16_t", "[-4711]", "[null]", "[{\"value\":-4711}]", "{\"a\":-4711}", "[0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<std::shared_ptr<std::int16_t>>>(
				  setType, "std::shared_ptr<std::int16_t>", "[-4711]", "[null]", "[{\"value\":-4711}]", "{\"a\":-4711}", "[null]")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_UINT16_T + 0)
	failed = !Testee::ArrayTestSuite<SetType<std::uint16_t>>(
				  setType, "std::uint16_t", "[4711]", "[null]", "[{\"value\":4711}]", "{\"a\":4711}", "[0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<std::shared_ptr<std::uint16_t>>>(
				  setType, "std::shared_ptr<std::uint16_t>", "[4711]", "[null]", "[{\"value\":4711}]", "{\"a\":4711}", "[null]")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_INT32_T + 0)
	failed = !Testee::ArrayTestSuite<SetType<std::int32_t>>(
				  setType, "std::int32_t", "[-47114711]", "[null]", "[{\"value\":-47114711}]", "{\"a\":-47114711}", "[0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<std::shared_ptr<std::int32_t>>>(
				  setType,
				  "std::shared_ptr<std::int32_t>",
				  "[-47114711]",
				  "[null]",
				  "[{\"value\":-47114711}]",
				  "{\"a\":-47114711}",
				  "[null]")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_UINT32_T + 0)
	failed = !Testee::ArrayTestSuite<SetType<std::uint32_t>>(
				  setType, "std::uint32_t", "[47114711]", "[null]", "[{\"value\":47114711}]", "{\"a\":47114711}", "[0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<std::shared_ptr<std::uint32_t>>>(
				  setType,
				  "std::shared_ptr<std::uint32_t>",
				  "[47114711]",
				  "[null]",
				  "[{\"value\":47114711}]",
				  "{\"a\":47114711}",
				  "[null]")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_INT64_T + 0)
	failed = !Testee::ArrayTestSuite<SetType<std::int64_t>>(
				  setType,
				  "std::int64_t",
				  "[-4711471147114711]",
				  "[null]",
				  "[{\"value\":-4711471147114711}]",
				  "{\"a\":-4711471147114711}",
				  "[0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<std::shared_ptr<std::int64_t>>>(
				  setType,
				  "std::shared_ptr<std::int64_t>",
				  "[-4711471147114711]",
				  "[null]",
				  "[{\"value\":-4711471147114711}]",
				  "{\"a\":-4711471147114711}",
				  "[null]")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_UINT64_T + 0)
	failed = !Testee::ArrayTestSuite<SetType<std::uint64_t>>(
				  setType,
				  "std::uint64_t",
				  "[4711471147114711]",
				  "[null]",
				  "[{\"value\":4711471147114711}]",
				  "{\"a\":4711471147114711}",
				  "[0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<std::shared_ptr<std::uint64_t>>>(
				  setType,
				  "std::shared_ptr<std::uint64_t>",
				  "[4711471147114711]",
				  "[null]",
				  "[{\"value\":4711471147114711}]",
				  "{\"a\":4711471147114711}",
				  "[null]")
				  .run() ||
			 failed;
#endif

	failed = !Testee::ArrayTestSuite<SetType<std::intmax_t>>(
				  setType,
				  "std::intmax_t",
				  "[-4711471147114711]",
				  "[null]",
				  "[{\"value\":-4711471147114711}]",
				  "{\"a\":-4711471147114711}",
				  "[0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<std::shared_ptr<std::intmax_t>>>(
				  setType,
				  "std::shared_ptr<std::intmax_t>",
				  "[-4711471147114711]",
				  "[null]",
				  "[{\"value\":-4711471147114711}]",
				  "{\"a\":-4711471147114711}",
				  "[null]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<std::uintmax_t>>(
				  setType,
				  "std::uintmax_t",
				  "[4711471147114711]",
				  "[null]",
				  "[{\"value\":4711471147114711}]",
				  "{\"a\":4711471147114711}",
				  "[0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<std::shared_ptr<std::uintmax_t>>>(
				  setType,
				  "std::shared_ptr<std::uintmax_t>",
				  "[4711471147114711]",
				  "[null]",
				  "[{\"value\":4711471147114711}]",
				  "{\"a\":4711471147114711}",
				  "[null]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<float>>(
				  setType, "float", "[3.25]", "[null]", "[{\"value\":3.25}]", "{\"a\":3.25}", "[0.0]", "[0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<std::shared_ptr<float>>>(
				  setType, "std::shared_ptr<float>", "[3.25]", "[null]", "[{\"value\":3.25}]", "{\"a\":3.25}", "[null]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<double>>(
				  setType, "double", "[3.25]", "[null]", "[{\"value\":3.25}]", "{\"a\":3.25}", "[0.0]", "[0]")
				  .run() ||
			 failed;

	failed = !Testee::ArrayTestSuite<SetType<std::shared_ptr<double>>>(
				  setType, "std::shared_ptr<double>", "[3.25]", "[null]", "[{\"value\":3.25}]", "{\"a\":3.25}", "[null]")
				  .run() ||
			 failed;

	failed =
		!Testee::ArrayTestSuite<SetType<bool>>(setType, "bool", "[true]", "[null]", "[{\"value\":true}]", "{\"a\":true}", "[false]")
			 .run() ||
		failed;

	failed = !Testee::ArrayTestSuite<SetType<std::shared_ptr<bool>>>(
				  setType, "std::shared_ptr<bool>", "[true]", "[null]", "[{\"value\":true}]", "{\"a\":true}", "[null]")
				  .run() ||
			 failed;

	failed = !Testee::SetTestSuite<SetType<std::string>, isMultiset>(setType, "std::string", "\"a\"", "\"b\"").run() || failed;

	failed = !Testee::SetTestSuite<SetType<std::shared_ptr<std::string>>, isMultiset>(
				  setType, "std::shared_ptr<std::string>", "\"a\"", "\"b\"")
				  .run() ||
			 failed;

	failed = !Testee::SetTestSuite<typename SetOfObject<SetType, isUnordered, Model::Object<std::string>>::Type, isMultiset>(
				  setType, "Model::Object<std::string>", "{\"value\":\"a\"}", "{\"value\":\"b\"}")
				  .run() ||
			 failed;

	failed = !Testee::SetTestSuite<
				  typename SetOfObject<SetType, isUnordered, std::shared_ptr<Model::Object<std::string>>>::Type,
				  isMultiset>(setType, "std::shared_ptr<Model::Object<std::string>>", "{\"value\":\"a\"}", "{\"value\":\"b\"}")
				  .run() ||
			 failed;

	return failed ? 1 : 0;
}

} // namespace Testee

#endif // Testee_arrayTest_INCLUDED
