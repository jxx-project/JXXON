//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>
#include <map>

namespace JXXON {
namespace Accessor {

template<>
GetMapElements<int, std::map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<int, std::map>::operator()(Json::MapBase<int, std::map>& map) const
{
	populateMap<int, std::map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt();});
}

template GetMapElements<int, std::map>::GetMapElements(const Json& json);
template void GetMapElements<int, std::map>::operator()(Json::MapBase<int, std::map>& map) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template<>
GetMapElements<std::int64_t, std::map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::int64_t, std::map>::operator()(Json::MapBase<std::int64_t, std::map>& map) const
{
	populateMap<std::int64_t, std::map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt64();});
}

template GetMapElements<std::int64_t, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::int64_t, std::map>::operator()(Json::MapBase<std::int64_t, std::map>& map) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template<>
GetMapElements<std::intmax_t, std::map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::intmax_t, std::map>::operator()(Json::MapBase<std::intmax_t, std::map>& map) const
{
	populateMap<std::intmax_t, std::map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asLargestInt();});
}

template GetMapElements<std::intmax_t, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::intmax_t, std::map>::operator()(Json::MapBase<std::intmax_t, std::map>& map) const;
#endif

} // namespace Accessor
} // namespace JXXON
