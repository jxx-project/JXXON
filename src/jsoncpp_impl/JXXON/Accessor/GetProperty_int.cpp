//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetProperty.hpp"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template<>
GetProperty<int>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
int GetProperty<int>::operator()() const
{
	return getChild<int>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asInt();});
}

template GetProperty<int>::GetProperty(const Json& json, const std::string& name);
template int GetProperty<int>::operator()() const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template<>
GetProperty<std::int64_t>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::int64_t GetProperty<std::int64_t>::operator()() const
{
	return getChild<std::int64_t>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asInt64();});
}

template GetProperty<std::int64_t>::GetProperty(const Json& json, const std::string& name);
template std::int64_t GetProperty<std::int64_t>::operator()() const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template<>
GetProperty<std::intmax_t>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::intmax_t GetProperty<std::intmax_t>::operator()() const
{
	return getChild<std::intmax_t>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asLargestInt();});
}

template GetProperty<std::intmax_t>::GetProperty(const Json& json, const std::string& name);
template std::intmax_t GetProperty<std::intmax_t>::operator()() const;
#endif

} // namespace Accessor
} // namespace JXXON
