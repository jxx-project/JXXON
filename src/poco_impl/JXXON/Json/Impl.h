//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Json_Impl_INCLUDED
#define JXXON_Json_Impl_INCLUDED

#include <string>
#include <ostream>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Array.h>

namespace JXXON {

class Json::Impl
{
public:
	class Object;
	class Array;

	virtual ~Impl()
	{
	}

	virtual Poco::JSON::Object::Ptr getObject() = 0;
	virtual Poco::JSON::Array::Ptr getArray() = 0;
	virtual void joinParent(Poco::JSON::Object::Ptr parent, const std::string& childName) const = 0;
	virtual void appendTo(Poco::JSON::Array::Ptr array) const = 0;
	virtual void stringify(std::ostream& out) const = 0;
	virtual std::unique_ptr<Impl> clone() const = 0;
};

class Json::Impl::Object : public Json::Impl
{
public:
	Object();
	Object(const Poco::JSON::Object::Ptr object);
	Object(const Object& other) = delete;
	Object& operator=(const Object& other) = delete;

	virtual ~Object()
	{
	}

	virtual Poco::JSON::Object::Ptr getObject() override;
	virtual Poco::JSON::Array::Ptr getArray() override;
	virtual void joinParent(Poco::JSON::Object::Ptr parent, const std::string& childName) const override;
	virtual void appendTo(Poco::JSON::Array::Ptr array) const override;
	virtual void stringify(std::ostream& out) const override;
	virtual std::unique_ptr<Json::Impl> clone() const override;

private:
	Poco::JSON::Object::Ptr object;
};

class Json::Impl::Array : public Json::Impl
{
public:
	Array();
	Array(const Poco::JSON::Array::Ptr array);
	Array(const Array& other) = delete;
	Array& operator=(const Array& other) = delete;

	virtual ~Array()
	{
	}

	virtual Poco::JSON::Object::Ptr getObject() override;
	virtual Poco::JSON::Array::Ptr getArray() override;
	virtual void joinParent(Poco::JSON::Object::Ptr parent, const std::string& childName) const override;
	virtual void appendTo(Poco::JSON::Array::Ptr array) const override;
	virtual void stringify(std::ostream& out) const override;
	virtual std::unique_ptr<Json::Impl> clone() const override;

private:
	Poco::JSON::Array::Ptr array;
};

} // namespace JXXON

#endif // JXXON_Json_Impl_INCLUDED
