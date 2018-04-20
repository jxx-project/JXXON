//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {


#if (_SIZEOF_UINT8_T + 0)
template<>
GetArrayElements<std::uint8_t>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::uint8_t>::operator()(Json::ArrayType<std::uint8_t>& array) const
{
	populateArray<std::uint8_t>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asUInt();});
}

template GetArrayElements<std::uint8_t>::GetArrayElements(const Json& json);
template void GetArrayElements<std::uint8_t>::operator()(Json::ArrayType<std::uint8_t>& array) const;
#endif

#if (_SIZEOF_UINT16_T + 0)
template<>
GetArrayElements<std::uint16_t>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::uint16_t>::operator()(Json::ArrayType<std::uint16_t>& array) const
{
	populateArray<std::uint16_t>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asUInt();});
}

template GetArrayElements<std::uint16_t>::GetArrayElements(const Json& json);
template void GetArrayElements<std::uint16_t>::operator()(Json::ArrayType<std::uint16_t>& array) const;
#endif

#if (_SIZEOF_UINT32_T + 0)
template<>
GetArrayElements<std::uint32_t>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::uint32_t>::operator()(Json::ArrayType<std::uint32_t>& array) const
{
	populateArray<std::uint32_t>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asUInt();});
}

template GetArrayElements<std::uint32_t>::GetArrayElements(const Json& json);
template void GetArrayElements<std::uint32_t>::operator()(Json::ArrayType<std::uint32_t>& array) const;
#endif

#if (_SIZEOF_UINT64_T + 0)
template<>
GetArrayElements<std::uint64_t>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::uint64_t>::operator()(Json::ArrayType<std::uint64_t>& array) const
{
	populateArray<std::uint64_t>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asUInt64();});
}

template GetArrayElements<std::uint64_t>::GetArrayElements(const Json& json);
template void GetArrayElements<std::uint64_t>::operator()(Json::ArrayType<std::uint64_t>& array) const;
#endif

#if (_SIZEOF_UINTMAX_T + 0) && !((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
template<>
GetArrayElements<std::uintmax_t>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::uintmax_t>::operator()(Json::ArrayType<std::uintmax_t>& array) const
{
	populateArray<std::uintmax_t>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asLargestUInt();});
}

template GetArrayElements<std::uintmax_t>::GetArrayElements(const Json& json);
template void GetArrayElements<std::uintmax_t>::operator()(Json::ArrayType<std::uintmax_t>& array) const;
#endif

}} // namespace JXXON::Accessor
