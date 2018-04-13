//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetProperty.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetProperty<unsigned int>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
unsigned int GetProperty<unsigned int>::operator()() const
{
	return getChild<unsigned int>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asUInt();});
}

template GetProperty<unsigned int>::GetProperty(const Json& json, const std::string& name);
template unsigned int GetProperty<unsigned int>::operator()() const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template<>
GetProperty<std::uint64_t>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::uint64_t GetProperty<std::uint64_t>::operator()() const
{
	return getChild<std::uint64_t>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asUInt64();});
}

template GetProperty<std::uint64_t>::GetProperty(const Json& json, const std::string& name);
template std::uint64_t GetProperty<std::uint64_t>::operator()() const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template<>
GetProperty<std::uintmax_t>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::uintmax_t GetProperty<std::uintmax_t>::operator()() const
{
	return getChild<std::uintmax_t>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asLargestUInt();});
}

template GetProperty<std::uintmax_t>::GetProperty(const Json& json, const std::string& name);
template std::uintmax_t GetProperty<std::uintmax_t>::operator()() const;
#endif

}} // namespace JXXON::Accessor
