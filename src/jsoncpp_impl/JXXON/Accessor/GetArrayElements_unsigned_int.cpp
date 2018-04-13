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

template<>
GetArrayElements<unsigned int>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<unsigned int>::operator()(Json::ArrayType<unsigned int>& array) const
{
	populateArray<unsigned int>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asUInt();});
}

template GetArrayElements<unsigned int>::GetArrayElements(const Json& json);
template void GetArrayElements<unsigned int>::operator()(Json::ArrayType<unsigned int>& array) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
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

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
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
