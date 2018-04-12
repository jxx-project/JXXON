//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Base_ArrayType_INCLUDED
#define JXXON_Base_ArrayType_INCLUDED

namespace JXXON { namespace Base {

/// Interface implemented by JSON array type containers.
template<class T>
class ArrayType
{
public:
	/// Virtual destructor.
	~ArrayType()
	{
	}

	/// Add element to array. Ordered containers like vector or list must append element at the end.
	virtual void addElement(const T& element) = 0;
};

}} // namespace JXXON::Base

#endif // JXXON_Base_ArrayType_INCLUDED
