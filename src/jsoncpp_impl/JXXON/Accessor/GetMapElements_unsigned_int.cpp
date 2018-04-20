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


#if (_SIZEOF_UINT8_T + 0)
template<>
GetMapElements<std::uint8_t>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::uint8_t>::operator()(Json::MapType<std::uint8_t>& map) const
{
	populateMap<std::uint8_t>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asUInt();});
}

template GetMapElements<std::uint8_t>::GetMapElements(const Json& json);
template void GetMapElements<std::uint8_t>::operator()(Json::MapType<std::uint8_t>& map) const;
#endif

#if (_SIZEOF_UINT16_T + 0)
template<>
GetMapElements<std::uint16_t>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::uint16_t>::operator()(Json::MapType<std::uint16_t>& map) const
{
	populateMap<std::uint16_t>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asUInt();});
}

template GetMapElements<std::uint16_t>::GetMapElements(const Json& json);
template void GetMapElements<std::uint16_t>::operator()(Json::MapType<std::uint16_t>& map) const;
#endif

#if (_SIZEOF_UINT32_T + 0)
template<>
GetMapElements<std::uint32_t>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::uint32_t>::operator()(Json::MapType<std::uint32_t>& map) const
{
	populateMap<std::uint32_t>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asUInt();});
}

template GetMapElements<std::uint32_t>::GetMapElements(const Json& json);
template void GetMapElements<std::uint32_t>::operator()(Json::MapType<std::uint32_t>& map) const;
#endif

#if (_SIZEOF_UINT64_T + 0)
template<>
GetMapElements<std::uint64_t>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::uint64_t>::operator()(Json::MapType<std::uint64_t>& map) const
{
	populateMap<std::uint64_t>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asUInt64();});
}

template GetMapElements<std::uint64_t>::GetMapElements(const Json& json);
template void GetMapElements<std::uint64_t>::operator()(Json::MapType<std::uint64_t>& map) const;
#endif

#if (_SIZEOF_UINTMAX_T + 0) && !((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
template<>
GetMapElements<std::uintmax_t>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::uintmax_t>::operator()(Json::MapType<std::uintmax_t>& map) const
{
	populateMap<std::uintmax_t>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asLargestUInt();});
}

template GetMapElements<std::uintmax_t>::GetMapElements(const Json& json);
template void GetMapElements<std::uintmax_t>::operator()(Json::MapType<std::uintmax_t>& map) const;
#endif

}} // namespace JXXON::Accessor