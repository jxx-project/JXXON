//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include <sstream>

namespace JXXON {
namespace {

struct CharReader
{
	static ::Json::CharReader& getInstance()
	{
		static CharReader instance;
		return *instance.reader;
	}

	CharReader(const CharReader&) = delete;
	void operator=(const CharReader&) = delete;

private:

	CharReader()
	{
		::Json::CharReaderBuilder builder;
		::Json::CharReaderBuilder::strictMode(&builder.settings_);
		reader = std::unique_ptr<::Json::CharReader>(builder.newCharReader());
	}

	std::unique_ptr<::Json::CharReader> reader;
};

struct StreamWriter
{
	static ::Json::StreamWriter& getInstance()
	{
		static StreamWriter instance;
		return *instance.writer;
	}

	StreamWriter(const StreamWriter&) = delete;
	void operator=(const StreamWriter&) = delete;

private:

	StreamWriter()
	{
		::Json::StreamWriterBuilder builder;
		builder["commentStyle"] = "None";
		builder["indentation"] = "";
		writer = std::unique_ptr<::Json::StreamWriter>(builder.newStreamWriter());
	}

	std::unique_ptr<::Json::StreamWriter> writer;
};

} // namespace

Json::Json() : pimpl(nullptr)
{
}

Json::Json(Json&& other) : pimpl(std::move(other.pimpl))
{
}

Json::Json(const std::string& document) : pimpl(new Impl())
{
	std::string errors;
	if (!CharReader::getInstance().parse(document.c_str(), document.c_str() + document.size(), &pimpl->value, &errors)) {
		throw Error(errors);
	}
	if (isNull()) {
		throw Error("Null value");
	}
}

Json& Json::operator=(Json&& other)
{
	if (this != &other) {
		pimpl = std::move(other.pimpl);
	}
	return *this;
}

Json::~Json()
{
}

bool Json::isNull() const
{
	return !pimpl || pimpl->value.isNull();
}

std::string Json::toString() const
{
	std::ostringstream out;
	StreamWriter::getInstance().write(isNull() ? ::Json::Value::null : pimpl->value, &out);
	return out.str();
}

std::istream& operator>>(std::istream& in, Json& json)
{
	std::string document(std::istreambuf_iterator<char>(in), {});
	std::string errors;
	std::unique_ptr<Json::Impl> pimpl(new Json::Impl);
	if (!CharReader::getInstance().parse(document.c_str(), document.c_str() + document.size(), &pimpl->value, &errors)) {
		throw Error(errors);
	}
	if (pimpl->value.isNull()) {
		throw Error("Null value");
	}
	json.pimpl = std::move(pimpl);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Json& json)
{
	out << json.toString();
	return out;
}

Json::Impl::Impl() {
}

Json::Impl::Impl(const ::Json::Value& value) : value(value)
{
}

::Json::Value Json::Impl::createEmptyObject() {
	::Json::Value result;
	result["dummy"] = "dummy";
	result.removeMember("dummy");
	return result;
}

const ::Json::Value Json::Impl::emptyObject = Json::Impl::createEmptyObject();

::Json::Value Json::Impl::createEmptyArray()
{
	::Json::Value result;
	result.resize(0);
	return result;
}

const ::Json::Value Json::Impl::emptyArray = Json::Impl::createEmptyArray();

Json::Json(std::unique_ptr<Json::Impl>&& pimpl) : pimpl(move(pimpl))
{
}

void Json::setTypeObject()
{
	if (!pimpl) {
		pimpl = std::unique_ptr<Impl>(new Impl(Impl::emptyObject));
	}
}

Json Json::getChild(const std::string& name) const
{
	if (!pimpl->value.isNull()) {
		try {
			auto child = pimpl->value.get(name, ::Json::Value::null);
			if (!child.isNull()) {
				return Json(std::unique_ptr<Impl>(new Json::Impl(child)));
			}
		} catch (std::exception& e) {
			throw Error(e.what());
		}
	}
	return Json();
}

void Json::setChild(const std::string& name, const Json& child)
{
	setTypeObject();
	pimpl->value[name] = child.pimpl->value;
}

void Json::setTypeArray()
{
	if (!pimpl) {
		pimpl = std::unique_ptr<Impl>(new Impl(Impl::emptyArray));
	}
}

void Json::append(const Json& element)
{
	pimpl->value.append(element.isNull() ? ::Json::Value::null : element.pimpl->value);
}

void Json::append(const std::function<void(const Json& element)>& append) const
{
	if (!pimpl->value.isNull()) {
		if (!pimpl->value.isArray()) {
			throw Error("Not an array");
		}
		try {
			for (auto i = pimpl->value.begin(); i != pimpl->value.end(); ++i) {
				append(i->isNull() ? Json() : Json(std::unique_ptr<Impl>(new Json::Impl(*i))));
			}
		} catch (std::exception& e) {
			throw Error(e.what());
		}
	}
}

void Json::insert(const std::string& key, const Json& element)
{
	if (!pimpl->value.isNull()) {
		if (!pimpl->value.isObject()) {
			throw Error("Not an object");
		}
		pimpl->value[key] = element.isNull() ? ::Json::Value::null : element.pimpl->value;
	}
}

void Json::insert(const std::function<void(const std::string& key, const Json& element)>& insert) const
{
	if (!pimpl->value.isNull()) {
		if (!pimpl->value.isObject()) {
			throw Error("Not an object");
		}
		try {
			for (auto i = pimpl->value.begin(); i != pimpl->value.end(); ++i) {
				insert(i.key().asString(), i->isNull() ? Json() : Json(std::unique_ptr<Impl>(new Json::Impl(*i))));
			}
		} catch (std::exception& e) {
			throw Error(e.what());
		}
	}
}

} // namespace JXXON
