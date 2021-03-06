//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Base_Vector_INCLUDED
#define JXXON_Base_Vector_INCLUDED

#include "JXXON/Json.h"
#include <Polymorphic/Vector.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::Vector<T, Allocator> implementing JXXON::Json::ArrayType<T>.
template<typename T, typename Allocator = std::allocator<T>>
class Vector : public Polymorphic::Vector<T, Allocator>, public JXXON::Json::ArrayType<T>
{
public:
	/// Construct empty vector.
	Vector()
	{
	}

	/// Construct vector of size n of default constructed elements.
	explicit Vector(typename Vector::size_type n) : Polymorphic::Vector<T, Allocator>(n)
	{
	}

	/// Construct vector of size n of copy of value constructed elements.
	Vector(typename Vector::size_type n, const T& value) : Polymorphic::Vector<T, Allocator>(n, value)
	{
	}

	/// Construct vector with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	Vector(InputIterator first, InputIterator last) : Polymorphic::Vector<T, Allocator>(first, last)
	{
	}

	/// Copy construct vector.
	Vector(const Vector& other) : Polymorphic::Vector<T, Allocator>(other)
	{
	}

	/// Move construct vector.
	Vector(Vector&& other) : Polymorphic::Vector<T, Allocator>(std::move(other))
	{
	}

	/// Initializer list constructor.
	Vector(std::initializer_list<T> initializerList) : Polymorphic::Vector<T, Allocator>(initializerList)
	{
	}

	/// Copy construct vector from delegate type.
	Vector(const typename Vector::DelegateType& other) : Polymorphic::Vector<T, Allocator>(other)
	{
	}

	/// Move construct vector from delegate type.
	Vector(typename Vector::DelegateType&& other) : Polymorphic::Vector<T, Allocator>(std::move(other))
	{
	}

	/// Virtual destructor.
	virtual ~Vector()
	{
	}

	/// Copy assign vector.
	Vector& operator=(const Vector& other)
	{
		return static_cast<Vector&>(Polymorphic::Vector<T, Allocator>::operator=(other));
	}

	/// Move assign vector.
	Vector& operator=(Vector&& other)
	{
		return static_cast<Vector&>(Polymorphic::Vector<T, Allocator>::operator=(std::move(other)));
	}

	/// Initializer list assignment.
	Vector& operator=(std::initializer_list<T> initializerList)
	{
		return static_cast<Vector&>(Polymorphic::Vector<T, Allocator>::operator=(initializerList));
	}

	/// Copy assign delegate type vector.
	Vector& operator=(const typename Vector::DelegateType& other)
	{
		return static_cast<Vector&>(Polymorphic::Vector<T, Allocator>::operator=(other));
	}

	/// Move assign delegate type vector.
	Vector& operator=(typename Vector::DelegateType&& other)
	{
		return static_cast<Vector&>(Polymorphic::Vector<T, Allocator>::operator=(std::move(other)));
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
