//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Base_Vector_INCLUDED
#define JXXON_Base_Vector_INCLUDED

#include "JXXON/Json.h"
#include <Polymorphic/Vector.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::Vector<T> implementing JXXON::Json::ArrayType<T>.
template<class T>
class Vector : public Polymorphic::Vector<T>, public JXXON::Json::ArrayType<T>
{
public:
	/// Construct empty vector.
	Vector()
	{
	}

	/// Construct vector of size n of default constructed elements.
	explicit Vector(typename Vector::size_type n) : Polymorphic::Vector<T>(n)
	{
	}

	/// Construct vector of size n of copy of value constructed elements.
	Vector(typename Vector::size_type n, const T& value) : Polymorphic::Vector<T>(n, value)
	{
	}

	/// Construct vector with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	Vector(InputIterator first, InputIterator last) : Polymorphic::Vector<T>(first, last)
	{
	}

	/// Copy construct vector.
	Vector(const Vector& other) : Polymorphic::Vector<T>(other)
	{
	}

	/// Move construct vector.
	Vector(Vector&& other) : Polymorphic::Vector<T>(std::move(other))
	{
	}

	/// Initializer list constructor.
	Vector(std::initializer_list<T> initializerList) : Polymorphic::Vector<T>(initializerList)
	{
	}

	/// Copy construct vector from delegate type.
	Vector(const typename Vector::DelegateType& other) : Polymorphic::Vector<T>(other)
	{
	}

	/// Move construct vector from delegate type.
	Vector(typename Vector::DelegateType&& other) : Polymorphic::Vector<T>(std::move(other))
	{
	}

	/// Virtual destructor.
	~Vector()
	{
	}

	virtual void addElement(const T& element) override
	{
		this->emplace_back(element);
	}

	virtual void forEach(const std::function<void(const T& element)>& f) const override
	{
		for (const auto& i : *this) {
			f(i);
		}
	}
};

}} // namespace JXXON::Base

#endif // JXXON_Base_Vector_INCLUDED
