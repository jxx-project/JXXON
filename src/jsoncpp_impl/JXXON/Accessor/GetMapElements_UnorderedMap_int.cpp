//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/UnorderedMap.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetMapElements<int, Base::UnorderedMap>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<int, Base::UnorderedMap>::operator()(Base::UnorderedMap<int>& map) const
{
	populateMap<int, Base::UnorderedMap>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt();});
}

template GetMapElements<int, Base::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<int, Base::UnorderedMap>::operator()(Base::UnorderedMap<int>& map) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template<>
GetMapElements<std::int64_t, Base::UnorderedMap>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::int64_t, Base::UnorderedMap>::operator()(Base::UnorderedMap<std::int64_t>& map) const
{
	populateMap<std::int64_t, Base::UnorderedMap>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt64();});
}

template GetMapElements<std::int64_t, Base::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<std::int64_t, Base::UnorderedMap>::operator()(Base::UnorderedMap<std::int64_t>& map) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template<>
GetMapElements<std::intmax_t, Base::UnorderedMap>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::intmax_t, Base::UnorderedMap>::operator()(Base::UnorderedMap<std::intmax_t>& map) const
{
	populateMap<std::intmax_t, Base::UnorderedMap>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asLargestInt();});
}

template GetMapElements<std::intmax_t, Base::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<std::intmax_t, Base::UnorderedMap>::operator()(Base::UnorderedMap<std::intmax_t>& map) const;
#endif

}} // namespace JXXON::Accessor
