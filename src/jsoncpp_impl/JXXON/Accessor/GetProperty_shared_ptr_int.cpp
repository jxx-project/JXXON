//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetProperty_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {


#if (_SIZEOF_INT8_T + 0)
template<>
GetProperty<std::shared_ptr<std::int8_t>>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::shared_ptr<std::int8_t> GetProperty<std::shared_ptr<std::int8_t>>::operator()() const
{
	return getChild<std::shared_ptr<std::int8_t>>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asInt();});
}

template GetProperty<std::shared_ptr<std::int8_t>>::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<std::int8_t> GetProperty<std::shared_ptr<std::int8_t>>::operator()() const;
#endif

#if (_SIZEOF_INT16_T + 0)
template<>
GetProperty<std::shared_ptr<std::int16_t>>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::shared_ptr<std::int16_t> GetProperty<std::shared_ptr<std::int16_t>>::operator()() const
{
	return getChild<std::shared_ptr<std::int16_t>>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asInt();});
}

template GetProperty<std::shared_ptr<std::int16_t>>::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<std::int16_t> GetProperty<std::shared_ptr<std::int16_t>>::operator()() const;
#endif

#if (_SIZEOF_INT32_T + 0)
template<>
GetProperty<std::shared_ptr<std::int32_t>>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::shared_ptr<std::int32_t> GetProperty<std::shared_ptr<std::int32_t>>::operator()() const
{
	return getChild<std::shared_ptr<std::int32_t>>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asInt();});
}

template GetProperty<std::shared_ptr<std::int32_t>>::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<std::int32_t> GetProperty<std::shared_ptr<std::int32_t>>::operator()() const;
#endif

#if (_SIZEOF_INT64_T + 0)
template<>
GetProperty<std::shared_ptr<std::int64_t>>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::shared_ptr<std::int64_t> GetProperty<std::shared_ptr<std::int64_t>>::operator()() const
{
	return getChild<std::shared_ptr<std::int64_t>>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asInt64();});
}

template GetProperty<std::shared_ptr<std::int64_t>>::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<std::int64_t> GetProperty<std::shared_ptr<std::int64_t>>::operator()() const;
#endif

#if (_SIZEOF_INTMAX_T + 0) && !((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
template<>
GetProperty<std::shared_ptr<std::intmax_t>>::GetProperty(const Json& json, const std::string& name) : json(json), name(name)
{
}

template<>
std::shared_ptr<std::intmax_t> GetProperty<std::shared_ptr<std::intmax_t>>::operator()() const
{
	return getChild<std::shared_ptr<std::intmax_t>>(json.pimpl->value, name, [](const ::Json::Value& value){return value.asLargestInt();});
}

template GetProperty<std::shared_ptr<std::intmax_t>>::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<std::intmax_t> GetProperty<std::shared_ptr<std::intmax_t>>::operator()() const;
#endif

}} // namespace JXXON::Accessor
