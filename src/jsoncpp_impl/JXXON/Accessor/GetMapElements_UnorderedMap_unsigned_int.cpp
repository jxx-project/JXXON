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
#include <Polymorphic/UnorderedMap.h>

namespace JXXON {
namespace Accessor {

template<>
GetMapElements<unsigned int, Polymorphic::UnorderedMap>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<unsigned int, Polymorphic::UnorderedMap>::operator()(Json::MapBase<unsigned int, Polymorphic::UnorderedMap>& map) const
{
	populateMap<unsigned int, Polymorphic::UnorderedMap>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asUInt();});
}

template GetMapElements<unsigned int, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<unsigned int, Polymorphic::UnorderedMap>::operator()(Json::MapBase<unsigned int, Polymorphic::UnorderedMap>& map) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template<>
GetMapElements<std::uint64_t, Polymorphic::UnorderedMap>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::uint64_t, Polymorphic::UnorderedMap>::operator()(Json::MapBase<std::uint64_t, Polymorphic::UnorderedMap>& map) const
{
	populateMap<std::uint64_t, Polymorphic::UnorderedMap>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asUInt64();});
}

template GetMapElements<std::uint64_t, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<std::uint64_t, Polymorphic::UnorderedMap>::operator()(Json::MapBase<std::uint64_t, Polymorphic::UnorderedMap>& map) const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template<>
GetMapElements<std::uintmax_t, Polymorphic::UnorderedMap>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::uintmax_t, Polymorphic::UnorderedMap>::operator()(Json::MapBase<std::uintmax_t, Polymorphic::UnorderedMap>& map) const
{
	populateMap<std::uintmax_t, Polymorphic::UnorderedMap>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asLargestUInt();});
}

template GetMapElements<std::uintmax_t, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<std::uintmax_t, Polymorphic::UnorderedMap>::operator()(Json::MapBase<std::uintmax_t, Polymorphic::UnorderedMap>& map) const;
#endif

} // namespace Accessor
} // namespace JXXON