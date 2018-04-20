//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {


#if (_SIZEOF_INT8_T + 0)
template<>
GetMapElements<std::int8_t>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::int8_t>::operator()(Json::MapType<std::int8_t>& map) const
{
	populateMap<std::int8_t>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt();});
}

template GetMapElements<std::int8_t>::GetMapElements(const Json& json);
template void GetMapElements<std::int8_t>::operator()(Json::MapType<std::int8_t>& map) const;
#endif

#if (_SIZEOF_INT16_T + 0)
template<>
GetMapElements<std::int16_t>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::int16_t>::operator()(Json::MapType<std::int16_t>& map) const
{
	populateMap<std::int16_t>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt();});
}

template GetMapElements<std::int16_t>::GetMapElements(const Json& json);
template void GetMapElements<std::int16_t>::operator()(Json::MapType<std::int16_t>& map) const;
#endif

#if (_SIZEOF_INT32_T + 0)
template<>
GetMapElements<std::int32_t>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::int32_t>::operator()(Json::MapType<std::int32_t>& map) const
{
	populateMap<std::int32_t>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt();});
}

template GetMapElements<std::int32_t>::GetMapElements(const Json& json);
template void GetMapElements<std::int32_t>::operator()(Json::MapType<std::int32_t>& map) const;
#endif

#if (_SIZEOF_INT64_T + 0)
template<>
GetMapElements<std::int64_t>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::int64_t>::operator()(Json::MapType<std::int64_t>& map) const
{
	populateMap<std::int64_t>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt64();});
}

template GetMapElements<std::int64_t>::GetMapElements(const Json& json);
template void GetMapElements<std::int64_t>::operator()(Json::MapType<std::int64_t>& map) const;
#endif

#if (_SIZEOF_INTMAX_T + 0) && !((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
template<>
GetMapElements<std::intmax_t>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::intmax_t>::operator()(Json::MapType<std::intmax_t>& map) const
{
	populateMap<std::intmax_t>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asLargestInt();});
}

template GetMapElements<std::intmax_t>::GetMapElements(const Json& json);
template void GetMapElements<std::intmax_t>::operator()(Json::MapType<std::intmax_t>& map) const;
#endif

}} // namespace JXXON::Accessor
