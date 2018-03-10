//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetArrayElements.hpp"
#include <vector>

namespace JXXON {
namespace Accessor {

template<>
GetArrayElements<unsigned int, std::vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<unsigned int, std::vector>::operator()(Json::ArrayBase<unsigned int, std::vector>& array) const
{
	populateArray<unsigned int, std::vector>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asUInt();});
}

template GetArrayElements<unsigned int, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<unsigned int, std::vector>::operator()(Json::ArrayBase<unsigned int, std::vector>& array) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template<>
GetArrayElements<std::uint64_t, std::vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::uint64_t, std::vector>::operator()(Json::ArrayBase<std::uint64_t, std::vector>& array) const
{
	populateArray<std::uint64_t, std::vector>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asUInt64();});
}

template GetArrayElements<std::uint64_t, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::uint64_t, std::vector>::operator()(Json::ArrayBase<std::uint64_t, std::vector>& array) const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template<>
GetArrayElements<std::uintmax_t, std::vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::uintmax_t, std::vector>::operator()(Json::ArrayBase<std::uintmax_t, std::vector>& array) const
{
	populateArray<std::uintmax_t, std::vector>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asLargestUInt();});
}

template GetArrayElements<std::uintmax_t, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::uintmax_t, std::vector>::operator()(Json::ArrayBase<std::uintmax_t, std::vector>& array) const;
#endif

} // namespace Accessor
} // namespace JXXON
