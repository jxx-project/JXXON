//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetArrayElements_shared_ptr.hpp"
#include <cstdint>
#include <vector>

namespace JXXON {
namespace Accessor {

template<>
GetArrayElements<std::shared_ptr<unsigned int>, std::vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<unsigned int>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<unsigned int>, std::vector>& array) const
{
	populateArray<std::shared_ptr<unsigned int>, std::vector>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asUInt();});
}

template GetArrayElements<std::shared_ptr<unsigned int>, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<unsigned int>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<unsigned int>, std::vector>& array) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template<>
GetArrayElements<std::shared_ptr<std::uint64_t>, std::vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::uint64_t>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<std::uint64_t>, std::vector>& array) const
{
	populateArray<std::shared_ptr<std::uint64_t>, std::vector>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asUInt64();});
}

template GetArrayElements<std::shared_ptr<std::uint64_t>, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::uint64_t>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<std::uint64_t>, std::vector>& array) const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template<>
GetArrayElements<std::shared_ptr<std::uintmax_t>, std::vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::uintmax_t>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<std::uintmax_t>, std::vector>& array) const
{
	populateArray<std::shared_ptr<std::uintmax_t>, std::vector>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asLargestUInt();});
}

template GetArrayElements<std::shared_ptr<std::uintmax_t>, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::uintmax_t>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<std::uintmax_t>, std::vector>& array) const;
#endif

} // namespace Accessor
} // namespace JXXON
