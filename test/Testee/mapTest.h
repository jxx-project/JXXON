//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef Testee_mapTest_INCLUDED
#define Testee_mapTest_INCLUDED

#include "Testee/MapTestSuite.h"
#include "JXXON/Vector.h"
#include "JXXON/List.h"
#include "JXXON/Map.h"
#include "JXXON/UnorderedMap.h"
#include "Model/Object.h"
#include <cstdint>
#include <memory>
#include <string>

namespace Testee {

/// Test Maps.
template<template<typename...> class MapType>
int mapTest(const std::string& mapType)
{
	bool failed = false;

	failed = !Testee::MapTestSuite<MapType, std::string>(
		mapType,
		"std::string",
		"{\"key\":\"dummy\"}",
		"{\"key\":null}",
		"{\"key\":[\"dummy\"]}",
		"[\"dummy\"]",
		"{\"key\":\"\"}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, std::shared_ptr<std::string> >(
		mapType,
		"std::shared_ptr<std::string>",
		"{\"key\":\"dummy\"}",
		"{\"key\":null}",
		"{\"key\":[\"dummy\"]}",
		"[\"dummy\"]",
		"{\"key\":null}").run() || failed;

	failed = !Testee::MapTestSuite<MapType, int>(
		mapType,
		"int",
		"{\"key\":-4711}",
		"{\"key\":null}",
		"{\"key\":[-4711]}",
		"[-4711]",
		"{\"key\":0}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, std::shared_ptr<int> >(
		mapType,
		"std::shared_ptr<int>",
		"{\"key\":-4711}",
		"{\"key\":null}",
		"{\"key\":[-4711]}",
		"[-4711]",
		"{\"key\":null}").run() || failed;

	failed = !Testee::MapTestSuite<MapType, unsigned int>(
		mapType,
		"unsigned int",
		"{\"key\":4711}",
		"{\"key\":null}",
		"{\"key\":[4711]}",
		"[4711]",
		"{\"key\":0}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, std::shared_ptr<unsigned int> >(
		mapType,
		"std::shared_ptr<unsigned int>",
		"{\"key\":4711}",
		"{\"key\":null}",
		"{\"key\":[4711]}",
		"[4711]",
		"{\"key\":null}").run() || failed;

	failed = !Testee::MapTestSuite<MapType, std::int64_t>(
		mapType,
		"std::int64_t",
		"{\"key\":-4711471147114711}",
		"{\"key\":null}",
		"{\"key\":[-4711471147114711]}",
		"[-4711471147114711]",
		"{\"key\":0}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, std::shared_ptr<std::int64_t> >(
		mapType,
		"std::shared_ptr<std::int64_t>",
		"{\"key\":-4711471147114711}",
		"{\"key\":null}",
		"{\"key\":[-4711471147114711]}",
		"[-4711471147114711]",
		"{\"key\":null}").run() || failed;

	failed = !Testee::MapTestSuite<MapType, std::uint64_t>(
		mapType,
		"std::uint64_t",
		"{\"key\":4711471147114711}",
		"{\"key\":null}",
		"{\"key\":[4711471147114711]}",
		"[4711471147114711]",
		"{\"key\":0}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, std::shared_ptr<std::uint64_t> >(
		mapType,
		"std::shared_ptr<std::uint64_t>",
		"{\"key\":4711471147114711}",
		"{\"key\":null}",
		"{\"key\":[4711471147114711]}",
		"[4711471147114711]",
		"{\"key\":null}").run() || failed;

	failed = !Testee::MapTestSuite<MapType, std::intmax_t>(
		mapType,
		"std::intmax_t",
		"{\"key\":-4711471147114711}",
		"{\"key\":null}",
		"{\"key\":[-4711471147114711]}",
		"[-4711471147114711]",
		"{\"key\":0}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, std::shared_ptr<std::intmax_t> >(
		mapType,
		"std::shared_ptr<std::intmax_t>",
		"{\"key\":-4711471147114711}",
		"{\"key\":null}",
		"{\"key\":[-4711471147114711]}",
		"[-4711471147114711]",
		"{\"key\":null}").run() || failed;

	failed = !Testee::MapTestSuite<MapType, std::uintmax_t>(
		mapType,
		"std::uintmax_t",
		"{\"key\":4711471147114711}",
		"{\"key\":null}",
		"{\"key\":[4711471147114711]}",
		"[4711471147114711]",
		"{\"key\":0}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, std::shared_ptr<std::uintmax_t> >(
		mapType,
		"std::shared_ptr<std::uintmax_t>",
		"{\"key\":4711471147114711}",
		"{\"key\":null}",
		"{\"key\":[4711471147114711]}",
		"[4711471147114711]",
		"{\"key\":null}").run() || failed;

	failed = !Testee::MapTestSuite<MapType, float>(
		mapType,
		"float",
		"{\"key\":3.25}",
		"{\"key\":null}",
		"{\"key\":[3.25]}",
		"[3.25]",
		"{\"key\":0.0}",
		"{\"key\":0}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, std::shared_ptr<float> >(
		mapType,
		"std::shared_ptr<float>",
		"{\"key\":3.25}",
		"{\"key\":null}",
		"{\"key\":[3.25]}",
		"[3.25]",
		"{\"key\":null}").run() || failed;

	failed = !Testee::MapTestSuite<MapType, double>(
		mapType,
		"double",
		"{\"key\":3.25}",
		"{\"key\":null}",
		"{\"key\":[3.25]}",
		"[3.25]",
		"{\"key\":0.0}",
		"{\"key\":0}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, std::shared_ptr<double> >(
		mapType,
		"std::shared_ptr<double>",
		"{\"key\":3.25}",
		"{\"key\":null}",
		"{\"key\":[3.25]}",
		"[3.25]",
		"{\"key\":null}").run() || failed;

	failed = !Testee::MapTestSuite<MapType, bool>(
		mapType,
		"bool",
		"{\"key\":true}",
		"{\"key\":null}",
		"{\"key\":[true]}",
		"[true]",
		"{\"key\":false}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, std::shared_ptr<bool> >(
		mapType,
		"std::shared_ptr<bool>",
		"{\"key\":true}",
		"{\"key\":null}",
		"{\"key\":[true]}",
		"[true]",
		"{\"key\":null}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, Model::Object<std::string> >(
		mapType,
		"Model::Object<std::string>",
		"{\"key\":{\"value\":\"dummy\"}}",
		"{\"key\":null}",
		"{\"key\":[{\"value\":\"dummy\"}]}",
		"[{\"value\":\"dummy\"}]",
		"{\"key\":{\"value\":\"\"}}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, std::shared_ptr< Model::Object<std::string> > >(
		mapType,
		"std::shared_ptr<Model::Object<std::string>>",
		"{\"key\":{\"value\":\"dummy\"}}",
		"{\"key\":null}",
		"{\"key\":[{\"value\":\"dummy\"}]}",
		"[{\"value\":\"dummy\"}]",
		"{\"key\":null}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, JXXON::Vector<std::string> >(
		mapType,
		"JXXON::Vector<std::string>",
		"{\"key\":[\"a\",\"b\"]}",
		"{\"key\":null}",
		"{\"key\":{\"value\":\"dummy\"}}",
		"[{\"value\":[\"a\",\"b\"]}]",
		"{\"key\":[]}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, std::shared_ptr< JXXON::Vector<std::string> > >(
		mapType,
		"std::shared_ptr<JXXON::Vector<std::string>>",
		"{\"key\":[\"a\",\"b\"]}",
		"{\"key\":null}",
		"{\"key\":{\"value\":\"dummy\"}}",
		"[{\"value\":[\"a\",\"b\"]}]",
		"{\"key\":null}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, JXXON::List<std::string> >(
		mapType,
		"JXXON::List<std::string>",
		"{\"key\":[\"a\",\"b\"]}",
		"{\"key\":null}",
		"{\"key\":{\"value\":\"dummy\"}}",
		"[{\"value\":[\"a\",\"b\"]}]",
		"{\"key\":[]}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, std::shared_ptr< JXXON::List<std::string> > >(
		mapType,
		"std::shared_ptr<JXXON::List<std::string>>",
		"{\"key\":[\"a\",\"b\"]}",
		"{\"key\":null}",
		"{\"key\":{\"value\":\"dummy\"}}",
		"[{\"value\":[\"a\",\"b\"]}]",
		"{\"key\":null}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, JXXON::Map<std::string> >(
		mapType,
		"JXXON::Map<std::string>",
		"{\"key\":{\"key\":\"dummy\"}}",
		"{\"key\":null}",
		"{\"key\":[{\"key\":\"dummy\"}]}",
		"[{\"key\":\"dummy\"}]",
		"{\"key\":{}}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, std::shared_ptr< JXXON::Map<std::string> > >(
		mapType,
		"std::shared_ptr<JXXON::Map<std::string>>",
		"{\"key\":{\"key\":\"dummy\"}}",
		"{\"key\":null}",
		"{\"key\":[{\"key\":\"dummy\"}]}",
		"[{\"key\":\"dummy\"}]",
		"{\"key\":null}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, JXXON::UnorderedMap<std::string> >(
		mapType,
		"JXXON::UnorderedMap<std::string>",
		"{\"key\":{\"key\":\"dummy\"}}",
		"{\"key\":null}",
		"{\"key\":[{\"key\":\"dummy\"}]}",
		"[{\"key\":\"dummy\"}]",
		"{\"key\":{}}").run() || failed;

	failed = !Testee::MapTestSuite< MapType, std::shared_ptr< JXXON::UnorderedMap<std::string> > >(
		mapType,
		"std::shared_ptr<JXXON::UnorderedMap<std::string>>",
		"{\"key\":{\"key\":\"dummy\"}}",
		"{\"key\":null}",
		"{\"key\":[{\"key\":\"dummy\"}]}",
		"[{\"key\":\"dummy\"}]",
		"{\"key\":null}").run() || failed;

	return failed ? 1 : 0;
}

} // namespace Testee

#endif // Testee_mapTest_INCLUDED
