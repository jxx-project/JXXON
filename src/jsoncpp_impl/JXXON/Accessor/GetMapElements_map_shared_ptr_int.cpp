//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>
#include <map>

namespace JXXON {
namespace Accessor {

template<>
GetMapElements<std::shared_ptr<int>, std::map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<int>, std::map>::operator()(Json::MapBase<std::shared_ptr<int>, std::map>& map) const
{
	populateMap<std::shared_ptr<int>, std::map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt();});
}

template GetMapElements<std::shared_ptr<int>, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<int>, std::map>::operator()(Json::MapBase<std::shared_ptr<int>, std::map>& map) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template<>
GetMapElements<std::shared_ptr<std::int64_t>, std::map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<std::int64_t>, std::map>::operator()(Json::MapBase<std::shared_ptr<std::int64_t>, std::map>& map) const
{
	populateMap<std::shared_ptr<std::int64_t>, std::map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt64();});
}

template GetMapElements<std::shared_ptr<std::int64_t>, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::int64_t>, std::map>::operator()(Json::MapBase<std::shared_ptr<std::int64_t>, std::map>& map) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template<>
GetMapElements<std::shared_ptr<std::intmax_t>, std::map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<std::intmax_t>, std::map>::operator()(Json::MapBase<std::shared_ptr<std::intmax_t>, std::map>& map) const
{
	populateMap<std::shared_ptr<std::intmax_t>, std::map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asLargestInt();});
}

template GetMapElements<std::shared_ptr<std::intmax_t>, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::intmax_t>, std::map>::operator()(Json::MapBase<std::shared_ptr<std::intmax_t>, std::map>& map) const;
#endif

} // namespace Accessor
} // namespace JXXON
