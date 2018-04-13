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

template<>
GetMapElements<int>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<int>::operator()(Json::MapType<int>& map) const
{
	populateMap<int>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt();});
}

template GetMapElements<int>::GetMapElements(const Json& json);
template void GetMapElements<int>::operator()(Json::MapType<int>& map) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
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

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
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
