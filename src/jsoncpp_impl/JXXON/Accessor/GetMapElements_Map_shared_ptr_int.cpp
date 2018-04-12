//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/Map.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetMapElements<std::shared_ptr<int>, Base::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<int>, Base::Map>::operator()(Base::Map<std::shared_ptr<int>>& map) const
{
	populateMap<std::shared_ptr<int>, Base::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt();});
}

template GetMapElements<std::shared_ptr<int>, Base::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<int>, Base::Map>::operator()(Base::Map<std::shared_ptr<int>>& map) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template<>
GetMapElements<std::shared_ptr<std::int64_t>, Base::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<std::int64_t>, Base::Map>::operator()(Base::Map<std::shared_ptr<std::int64_t>>& map) const
{
	populateMap<std::shared_ptr<std::int64_t>, Base::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt64();});
}

template GetMapElements<std::shared_ptr<std::int64_t>, Base::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::int64_t>, Base::Map>::operator()(Base::Map<std::shared_ptr<std::int64_t>>& map) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template<>
GetMapElements<std::shared_ptr<std::intmax_t>, Base::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<std::intmax_t>, Base::Map>::operator()(Base::Map<std::shared_ptr<std::intmax_t>>& map) const
{
	populateMap<std::shared_ptr<std::intmax_t>, Base::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asLargestInt();});
}

template GetMapElements<std::shared_ptr<std::intmax_t>, Base::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::intmax_t>, Base::Map>::operator()(Base::Map<std::shared_ptr<std::intmax_t>>& map) const;
#endif

}} // namespace JXXON::Accessor
