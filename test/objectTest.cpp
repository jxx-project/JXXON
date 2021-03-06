//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Model/Object.h"
#include "JXXON/List.h"
#include "JXXON/Map.h"
#include "JXXON/UnorderedMap.h"
#include "JXXON/Vector.h"
#include "Testee/ObjectTestSuite.h"
#include <cstdint>
#include <memory>
#include <string>

int main(int argc, char* argv[])
{
	bool failed = false;

	failed = !Testee::ObjectTestSuite<std::string>(
				  "std::string", "{\"value\":\"dummy\"}", "{\"value\":{\"inner\":\"dummy\"}}", "{\"value\":\"\"}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<std::string>>(
				  "std::shared_ptr<std::string>", "{\"value\":\"dummy\"}", "{\"value\":{\"inner\":\"dummy\"}}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<int>("int", "{\"value\":-4711}", "{\"value\":\"invalid\"}", "{\"value\":0}").run() || failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<int>>("std::shared_ptr<int>", "{\"value\":-4711}", "{\"value\":\"invalid\"}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<unsigned int>("unsigned int", "{\"value\":4711}", "{\"value\":\"invalid\"}", "{\"value\":0}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<unsigned int>>(
				  "std::shared_ptr<unsigned int>", "{\"value\":4711}", "{\"value\":\"invalid\"}")
				  .run() ||
			 failed;

#if (_SIZEOF_INT8_T + 0)
	failed =
		!Testee::ObjectTestSuite<std::int8_t>("std::int8_t", "{\"value\":-47}", "{\"value\":\"invalid\"}", "{\"value\":0}").run() ||
		failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<std::int8_t>>(
				  "std::shared_ptr<std::int8_t>", "{\"value\":-47}", "{\"value\":\"invalid\"}")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_UINT8_T + 0)
	failed = !Testee::ObjectTestSuite<std::uint8_t>("std::uint8_t", "{\"value\":47}", "{\"value\":\"invalid\"}", "{\"value\":0}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<std::uint8_t>>(
				  "std::shared_ptr<std::uint8_t>", "{\"value\":47}", "{\"value\":\"invalid\"}")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_INT16_T + 0)
	failed = !Testee::ObjectTestSuite<std::int16_t>("std::int16_t", "{\"value\":-4711}", "{\"value\":\"invalid\"}", "{\"value\":0}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<std::int16_t>>(
				  "std::shared_ptr<std::int16_t>", "{\"value\":-4711}", "{\"value\":\"invalid\"}")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_UINT16_T + 0)
	failed =
		!Testee::ObjectTestSuite<std::uint16_t>("std::uint16_t", "{\"value\":4711}", "{\"value\":\"invalid\"}", "{\"value\":0}")
			 .run() ||
		failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<std::uint16_t>>(
				  "std::shared_ptr<std::uint16_t>", "{\"value\":4711}", "{\"value\":\"invalid\"}")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_INT32_T + 0)
	failed =
		!Testee::ObjectTestSuite<std::int32_t>("std::int32_t", "{\"value\":-47114711}", "{\"value\":\"invalid\"}", "{\"value\":0}")
			 .run() ||
		failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<std::int32_t>>(
				  "std::shared_ptr<std::int32_t>", "{\"value\":-47114711}", "{\"value\":\"invalid\"}")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_UINT32_T + 0)
	failed =
		!Testee::ObjectTestSuite<std::uint32_t>("std::uint32_t", "{\"value\":47114711}", "{\"value\":\"invalid\"}", "{\"value\":0}")
			 .run() ||
		failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<std::uint32_t>>(
				  "std::shared_ptr<std::uint32_t>", "{\"value\":47114711}", "{\"value\":\"invalid\"}")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_INT64_T + 0)
	failed = !Testee::ObjectTestSuite<std::int64_t>(
				  "std::int64_t", "{\"value\":-4711471147114711}", "{\"value\":\"invalid\"}", "{\"value\":0}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<std::int64_t>>(
				  "std::shared_ptr<std::int64_t>", "{\"value\":-4711471147114711}", "{\"value\":\"invalid\"}")
				  .run() ||
			 failed;
#endif

#if (_SIZEOF_UINT64_T + 0)
	failed = !Testee::ObjectTestSuite<std::uint64_t>(
				  "std::uint64_t", "{\"value\":4711471147114711}", "{\"value\":\"invalid\"}", "{\"value\":0}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<std::uint64_t>>(
				  "std::shared_ptr<std::uint64_t>", "{\"value\":4711471147114711}", "{\"value\":\"invalid\"}")
				  .run() ||
			 failed;
#endif

	failed = !Testee::ObjectTestSuite<std::intmax_t>(
				  "std::intmax_t", "{\"value\":-4711471147114711}", "{\"value\":\"invalid\"}", "{\"value\":0}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<std::intmax_t>>(
				  "std::shared_ptr<std::intmax_t>", "{\"value\":-4711471147114711}", "{\"value\":\"invalid\"}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<std::uintmax_t>(
				  "std::uintmax_t", "{\"value\":4711471147114711}", "{\"value\":\"invalid\"}", "{\"value\":0}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<std::uintmax_t>>(
				  "std::shared_ptr<std::uintmax_t>", "{\"value\":4711471147114711}", "{\"value\":\"invalid\"}")
				  .run() ||
			 failed;

	failed =
		!Testee::ObjectTestSuite<float>("float", "{\"value\":3.25}", "{\"value\":\"invalid\"}", "{\"value\":0.0}", "{\"value\":0}")
			 .run() ||
		failed;

	failed =
		!Testee::ObjectTestSuite<std::shared_ptr<float>>("std::shared_ptr<float>", "{\"value\":3.25}", "{\"value\":\"invalid\"}")
			 .run() ||
		failed;

	failed = !Testee::ObjectTestSuite<double>(
				  "double", "{\"value\":3.25}", "{\"value\":\"invalid\"}", "{\"value\":0.0}", "{\"value\":0}")
				  .run() ||
			 failed;

	failed =
		!Testee::ObjectTestSuite<std::shared_ptr<double>>("std::shared_ptr<double>", "{\"value\":3.25}", "{\"value\":\"invalid\"}")
			 .run() ||
		failed;

	failed =
		!Testee::ObjectTestSuite<bool>("bool", "{\"value\":true}", "{\"value\":\"invalid\"}", "{\"value\":false}").run() || failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<bool>>("std::shared_ptr<bool>", "{\"value\":true}", "{\"value\":\"invalid\"}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<Model::Object<std::string>>(
				  "Model::Object<std::string>",
				  "{\"value\":{\"value\":\"dummy\"}}",
				  "{\"value\":\"invalid\"}",
				  "{\"value\":{\"value\":\"\"}}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<Model::Object<std::string>>>(
				  "std::shared_ptr<Model::Object<std::string>>", "{\"value\":{\"value\":\"dummy\"}}", "{\"value\":\"invalid\"}")
				  .run() ||
			 failed;

	failed =
		!Testee::ObjectTestSuite<JXXON::Vector<std::string>>(
			 "JXXON::Vector<std::string>", "{\"value\":[\"a\",\"b\",\"c\"]}", "{\"value\":{\"key\":\"value\"}}", "{\"value\":[]}")
			 .run() ||
		failed;

	failed =
		!Testee::ObjectTestSuite<std::shared_ptr<JXXON::Vector<std::string>>>(
			 "std::shared_ptr<JXXON::Vector<std::string>>", "{\"value\":[\"a\",\"b\",\"c\"]}", "{\"value\":{\"key\":\"value\"}}")
			 .run() ||
		failed;

	failed =
		!Testee::ObjectTestSuite<JXXON::List<std::string>>(
			 "JXXON::List<std::string>", "{\"value\":[\"a\",\"b\",\"c\"]}", "{\"value\":{\"key\":\"value\"}}", "{\"value\":[]}")
			 .run() ||
		failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<JXXON::List<std::string>>>(
				  "std::shared_ptr<JXXON::List<std::string>>", "{\"value\":[\"a\",\"b\",\"c\"]}", "{\"value\":{\"key\":\"value\"}}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<JXXON::Map<std::string>>(
				  "JXXON::Map<std::string>", "{\"value\":{\"key\":\"value\"}}", "{\"value\":[\"a\",\"b\",\"c\"]}", "{\"value\":{}}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<JXXON::Map<std::string>>>(
				  "std::shared_ptr<JXXON::Map<std::string>>", "{\"value\":{\"key\":\"value\"}}", "{\"value\":[\"a\",\"b\",\"c\"]}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<JXXON::UnorderedMap<std::string>>(
				  "JXXON::UnorderedMap<std::string>",
				  "{\"value\":{\"key\":\"value\"}}",
				  "{\"value\":[\"a\",\"b\",\"c\"]}",
				  "{\"value\":{}}")
				  .run() ||
			 failed;

	failed = !Testee::ObjectTestSuite<std::shared_ptr<JXXON::UnorderedMap<std::string>>>(
				  "std::shared_ptr<JXXON::UnorderedMap<std::string>>",
				  "{\"value\":{\"key\":\"value\"}}",
				  "{\"value\":[\"a\",\"b\",\"c\"]}")
				  .run() ||
			 failed;

	return failed ? 1 : 0;
}
