//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include <Poco/Dynamic/Var.h>
#include <Poco/JSON/Parser.h>

namespace JXXON {

Json::Json() : pimpl(nullptr)
{
}

Json::Json(Json&& other) : pimpl(std::move(other.pimpl))
{
}

Json::Json(const std::string& document) : pimpl(nullptr)
{
	try {
		Poco::JSON::Parser parser;
		auto var = parser.parse(document);
		try {
			pimpl = std::unique_ptr<Impl>(new Impl::Object(var.extract<Poco::JSON::Object::Ptr>()));
		} catch (Poco::BadCastException) {
			pimpl = std::unique_ptr<Impl>(new Impl::Array(var.extract<Poco::JSON::Array::Ptr>()));
		}
	} catch (Poco::Exception& e) {
		throw Error(e.message());
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
	return !pimpl;
}

std::string Json::toString() const
{
	std::ostringstream out;
	pimpl->stringify(out);
	return out.str();
}

std::istream& operator>>(std::istream& in, Json& json)
{
	try {
		Poco::JSON::Parser parser;
		auto var = parser.parse(in);
		try {
			json.pimpl = std::unique_ptr<Json::Impl>(new Json::Impl::Object(var.extract<Poco::JSON::Object::Ptr>()));
		} catch (Poco::BadCastException) {
			json.pimpl = std::unique_ptr<Json::Impl>(new Json::Impl::Array(var.extract<Poco::JSON::Array::Ptr>()));
		}
	} catch (Poco::Exception&) {
		in.setstate(std::ios::failbit);
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Json& json)
{
	json.pimpl->stringify(out);
	return out;
}

Json::Impl::Object::Object() : object(new Poco::JSON::Object)
{
}

Json::Impl::Object::Object(const Poco::JSON::Object::Ptr object) : object(object)
{
}

Poco::JSON::Object& Json::Impl::Object::getObject()
{
	return *object;
}

Poco::JSON::Array& Json::Impl::Object::getArray()
{
	throw Error("Not an array");
}

void Json::Impl::Object::joinParent(Poco::JSON::Object& parent, const std::string& childName) const
{
	parent.set(childName, object);
}

void Json::Impl::Object::appendTo(Poco::JSON::Array& array) const
{
	array.add(this->object);
}

void Json::Impl::Object::stringify(std::ostream& out) const
{
	object->stringify(out);
}

std::unique_ptr<Json::Impl> Json::Impl::Object::clone() const
{
	return std::unique_ptr<Json::Impl>(new Object(object));
}

Json::Impl::Array::Array() : array(new Poco::JSON::Array())
{
}

Json::Impl::Array::Array(const Poco::JSON::Array::Ptr array) : array(array)
{
}

Poco::JSON::Object& Json::Impl::Array::getObject()
{
	throw Error("Not an object");
}

Poco::JSON::Array& Json::Impl::Array::getArray()
{
	return *array;
}

void Json::Impl::Array::joinParent(Poco::JSON::Object& parent, const std::string& childName) const
{
	parent.set(childName, array);
}

void Json::Impl::Array::appendTo(Poco::JSON::Array& array) const
{
	array.add(this->array);
}

void Json::Impl::Array::stringify(std::ostream& out) const
{
	array->stringify(out);
}

std::unique_ptr<Json::Impl> Json::Impl::Array::clone() const
{
	return std::unique_ptr<Json::Impl>(new Array(array));
}

Json::Json(std::unique_ptr<Json::Impl>&& pimpl) : pimpl(std::move(pimpl))
{
}

void Json::setTypeObject()
{
	if (!pimpl) {
		pimpl = std::unique_ptr<Impl>(new Impl::Object());
	}
}

Json Json::getChild(const std::string& name) const
{
	auto& impl = pimpl->getObject();
	if (impl.has(name)) {
		if (impl.isObject(name)) {
			return Json(std::unique_ptr<Impl>(new Impl::Object(impl.getObject(name))));
		} else if (impl.isArray(name)) {
			return Json(std::unique_ptr<Impl>(new Impl::Array(impl.getArray(name))));
		} else {
			throw Error("Property is not object or array");
		}
	}
	return Json();
}

void Json::setChild(const std::string& name, const Json& child)
{
	setTypeObject();
	if (!child.isNull()) {
		child.pimpl->joinParent(pimpl->getObject(), name);
	}
}

void Json::setTypeArray()
{
	pimpl = std::unique_ptr<Impl>(new Impl::Array());
}

void Json::append(const Json& element)
{
	auto& impl = pimpl->getArray();
	if (element.isNull()) {
		impl.add(Poco::Dynamic::Var());
	} else {
		element.pimpl->appendTo(impl);
	}
}

void Json::append(const std::function<void(const Json& element)>& append) const
{
	auto& impl = pimpl->getArray();
	for (std::size_t i = 0; i != impl.size(); ++i) {
		if (impl.isNull(i)) {
			append(Json());
		} else {
			auto element = impl.get(i);
			if (impl.isObject(i)) {
				append(Json(std::unique_ptr<Impl>(new Impl::Object(element.extract<Poco::JSON::Object::Ptr>()))));
			} else if (impl.isArray(i)) {
				append(Json(std::unique_ptr<Impl>(new Impl::Array(element.extract<Poco::JSON::Array::Ptr>()))));
			} else {
				throw Error("Element is not object or array");
			}
		}
	}
}

void Json::insert(const std::string& key, const Json& element)
{
	auto& impl = pimpl->getObject();
	if (element.isNull()) {
		impl.set(key, Poco::Dynamic::Var());
	} else {
		element.pimpl->joinParent(impl, key);
	}
}

void Json::insert(const std::function<void(const std::string& key, const Json& element)>& insert) const
{
	for (const auto& i : pimpl->getObject()) {
		if (i.second.isEmpty()) {
			insert(i.first, Json());
		} else {
			try {
				try {
					insert(i.first, Json(std::unique_ptr<Impl>(new Impl::Object(i.second.extract<Poco::JSON::Object::Ptr>()))));
				} catch (Poco::BadCastException) {
					insert(i.first, Json(std::unique_ptr<Impl>(new Impl::Array(i.second.extract<Poco::JSON::Array::Ptr>()))));
				}
			} catch (Poco::Exception& e) {
				throw Error(e.message());
			}
		}
	}
}

} // namespace JXXON
