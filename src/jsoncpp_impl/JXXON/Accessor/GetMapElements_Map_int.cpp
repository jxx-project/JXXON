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
#include <Polymorphic/Map.h>

namespace JXXON {
namespace Accessor {

template<>
GetMapElements<int, Polymorphic::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<int, Polymorphic::Map>::operator()(Json::MapBase<int, Polymorphic::Map>& map) const
{
	populateMap<int, Polymorphic::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt();});
}

template GetMapElements<int, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<int, Polymorphic::Map>::operator()(Json::MapBase<int, Polymorphic::Map>& map) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template<>
GetMapElements<std::int64_t, Polymorphic::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::int64_t, Polymorphic::Map>::operator()(Json::MapBase<std::int64_t, Polymorphic::Map>& map) const
{
	populateMap<std::int64_t, Polymorphic::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt64();});
}

template GetMapElements<std::int64_t, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::int64_t, Polymorphic::Map>::operator()(Json::MapBase<std::int64_t, Polymorphic::Map>& map) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template<>
GetMapElements<std::intmax_t, Polymorphic::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::intmax_t, Polymorphic::Map>::operator()(Json::MapBase<std::intmax_t, Polymorphic::Map>& map) const
{
	populateMap<std::intmax_t, Polymorphic::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asLargestInt();});
}

template GetMapElements<std::intmax_t, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::intmax_t, Polymorphic::Map>::operator()(Json::MapBase<std::intmax_t, Polymorphic::Map>& map) const;
#endif

} // namespace Accessor
} // namespace JXXON
