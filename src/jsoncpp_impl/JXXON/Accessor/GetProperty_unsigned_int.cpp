//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetProperty.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {


#if (_SIZEOF_UINT8_T + 0)
template<>
GetProperty<std::uint8_t>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::uint8_t GetProperty<std::uint8_t>::operator()() const
{
	return getChild<std::uint8_t>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asUInt();});
}

template GetProperty<std::uint8_t>::GetProperty(const Json& json, const std::string& name);
template std::uint8_t GetProperty<std::uint8_t>::operator()() const;
#endif

#if (_SIZEOF_UINT16_T + 0)
template<>
GetProperty<std::uint16_t>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::uint16_t GetProperty<std::uint16_t>::operator()() const
{
	return getChild<std::uint16_t>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asUInt();});
}

template GetProperty<std::uint16_t>::GetProperty(const Json& json, const std::string& name);
template std::uint16_t GetProperty<std::uint16_t>::operator()() const;
#endif

#if (_SIZEOF_UINT32_T + 0)
template<>
GetProperty<std::uint32_t>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::uint32_t GetProperty<std::uint32_t>::operator()() const
{
	return getChild<std::uint32_t>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asUInt();});
}

template GetProperty<std::uint32_t>::GetProperty(const Json& json, const std::string& name);
template std::uint32_t GetProperty<std::uint32_t>::operator()() const;
#endif

#if (_SIZEOF_UINT64_T + 0)
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

#if (_SIZEOF_UINTMAX_T + 0) && !((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
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
