//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Base_MapType_INCLUDED
#define JXXON_Base_MapType_INCLUDED

#include <string>

namespace JXXON { namespace Base {

/// Interface implemented by JSON array type containers.
template<class T>
class MapType
{
public:
	/// Virtual destructor.
	~MapType()
	{
	}

	/// Add element to map.
	virtual void addElement(const std::string& key, const T& value) = 0;
};

}} // namespace JXXON::Base

#endif // JXXON_Base_MapType_INCLUDED
