//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetProperty_shared_ptr.tcc"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template<>
GetProperty<std::shared_ptr<unsigned int>>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::shared_ptr<unsigned int> GetProperty<std::shared_ptr<unsigned int>>::operator()() const
{
	return getChild<std::shared_ptr<unsigned int>>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asUInt();});
}

template GetProperty<std::shared_ptr<unsigned int>>::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<unsigned int> GetProperty<std::shared_ptr<unsigned int>>::operator()() const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template<>
GetProperty<std::shared_ptr<std::uint64_t>>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::shared_ptr<std::uint64_t> GetProperty<std::shared_ptr<std::uint64_t>>::operator()() const
{
	return getChild<std::shared_ptr<std::uint64_t>>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asUInt64();});
}

template GetProperty<std::shared_ptr<std::uint64_t>>::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<std::uint64_t> GetProperty<std::shared_ptr<std::uint64_t>>::operator()() const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template<>
GetProperty<std::shared_ptr<std::uintmax_t>>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::shared_ptr<std::uintmax_t> GetProperty<std::shared_ptr<std::uintmax_t>>::operator()() const
{
	return getChild<std::shared_ptr<std::uintmax_t>>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asLargestUInt();});
}

template GetProperty<std::shared_ptr<std::uintmax_t>>::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<std::uintmax_t> GetProperty<std::shared_ptr<std::uintmax_t>>::operator()() const;
#endif

} // namespace Accessor
} // namespace JXXON
