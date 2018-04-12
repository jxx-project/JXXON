//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Base_Vector_INCLUDED
#define JXXON_Base_Vector_INCLUDED

#include <Polymorphic/Vector.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::Vector<T> adding addElement(T&& element).
template<class T>
class Vector : public Polymorphic::Vector<T>
{
public:
	/// Construct empty vector.
	Vector()
	{
	}

	/// Construct vector of size n of default constructed elements.
	explicit Vector(typename Polymorphic::Vector<T>::size_type n) : Polymorphic::Vector<T>(n)
	{
	}

	/// Construct vector of size n of copy of value constructed elements.
	Vector(typename Polymorphic::Vector<T>::size_type n, const T& value) : Polymorphic::Vector<T>(n, value)
	{
	}

	/// Construct vector with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	Vector(InputIterator first, InputIterator last) : Polymorphic::Vector<T>(first, last)
	{
	}

	/// Copy construct vector.
	Vector(const Polymorphic::Vector<T>& other) : Polymorphic::Vector<T>(other)
	{
	}

	/// Move construct vector.
	Vector(Polymorphic::Vector<T>&& other) : Polymorphic::Vector<T>(std::move(other))
	{
	}

	/// Initializer list constructor.
	Vector(std::initializer_list<T> initializerList) : Polymorphic::Vector<T>(initializerList)
	{
	}

	/// Copy construct vector from delegate type.
	Vector(const typename Polymorphic::Vector<T>::DelegateType& other) : Polymorphic::Vector<T>(other)
	{
	}

	/// Move construct vector from delegate type.
	Vector(typename Polymorphic::Vector<T>::DelegateType&& other) : Polymorphic::Vector<T>(std::move(other))
	{
	}

	/// Virtual destructor .
	~Vector()
	{
	}

	virtual void addElement(const T& element)
	{
		this->emplace_back(element);
	}
};

}} // namespace JXXON::Base

#endif // JXXON_Base_Vector_INCLUDED
