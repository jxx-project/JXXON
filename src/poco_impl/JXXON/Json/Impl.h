//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Json_Impl_INCLUDED
#define JXXON_Json_Impl_INCLUDED

#include <Poco/JSON/Array.h>
#include <Poco/JSON/Object.h>
#include <ostream>
#include <string>

namespace JXXON {

class Json::Impl
{
public:
	class Object;
	class Array;

	virtual ~Impl()
	{
	}

	virtual Poco::JSON::Object& getObject() = 0;
	virtual Poco::JSON::Array& getArray() = 0;
	virtual void joinParent(Poco::JSON::Object& parent, const std::string& childName) const = 0;
	virtual void appendTo(Poco::JSON::Array& array) const = 0;
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

	virtual Poco::JSON::Object& getObject() override;
	virtual Poco::JSON::Array& getArray() override;
	virtual void joinParent(Poco::JSON::Object& parent, const std::string& childName) const override;
	virtual void appendTo(Poco::JSON::Array& array) const override;
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

	virtual Poco::JSON::Object& getObject() override;
	virtual Poco::JSON::Array& getArray() override;
	virtual void joinParent(Poco::JSON::Object& parent, const std::string& childName) const override;
	virtual void appendTo(Poco::JSON::Array& array) const override;
	virtual void stringify(std::ostream& out) const override;
	virtual std::unique_ptr<Json::Impl> clone() const override;

private:
	Poco::JSON::Array::Ptr array;
};

} // namespace JXXON

#endif // JXXON_Json_Impl_INCLUDED
