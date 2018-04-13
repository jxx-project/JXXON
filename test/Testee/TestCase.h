//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef TestCase_INCLUDED
#define TestCase_INCLUDED

#include <functional>
#include <stdexcept>
#include <sstream>

namespace Testee {

class TestCase
{
	template<typename T>
	static std::string toString(const T& value)
	{
		std::ostringstream out;
		out << value;
		return out.str();
	}

public:
	TestCase(const std::string& name, const std::function<void(void)>& runner) : name(name), runner(runner)
	{
	}

	void run()
	{
		try {
			runner();
		} catch (std::runtime_error& e) {
			std::string comment(e.what());
			throw std::runtime_error("Test case \"" + name + "\" failed." + (comment.empty() ? "" : " // " + comment));
		}
	}

	static void assert(bool passed, const char* comment = "")
	{
		if (!passed) {
			throw std::runtime_error(comment);
		}
	}

	template<typename T>
	static void assert_equal(const T& lhs, const T& rhs)
	{
		if (lhs != rhs) {
			throw std::runtime_error(toString(lhs) + " != " + toString(rhs));
		}
	}

	template<typename T>
	static void assert_equal(const T& lhs, const T& rhs, const T& altRhs)
	{
		if (lhs != rhs && lhs != altRhs) {
			throw std::runtime_error(toString(lhs) + " != " + toString(rhs) + " && " + toString(lhs) + " != " + toString(altRhs));
		}
	}

	template<typename Exception>
	static void assert_throw(const std::function<void(void)>& runner)
	{
		try {
			runner();
		} catch (Exception&) {
			return;
		} catch (std::exception& e) {
			std::string what(e.what());
			throw std::runtime_error("Unexpected exception" + (what.empty() ? "." : ": what=\"" + what + "\"."));
		} catch (...) {
			throw std::runtime_error("Unexpected exception.");
		}
		throw std::runtime_error("No exception.");
	}

private:
	std::string name;
	std::function<void(void)> runner;
};

} // namespace Testee

#endif // TestCase_INCLUDED
