//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements_shared_ptr.tcc"
#include <cstdint>
#include <vector>

namespace JXXON {
namespace Accessor {

template<>
GetArrayElements<std::shared_ptr<int>, std::vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<int>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<int>, std::vector>& array) const
{
	populateArray<std::shared_ptr<int>, std::vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asInt();});
}

template GetArrayElements<std::shared_ptr<int>, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<int>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<int>, std::vector>& array) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template<>
GetArrayElements<std::shared_ptr<std::int64_t>, std::vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::int64_t>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<std::int64_t>, std::vector>& array) const
{
	populateArray<std::shared_ptr<std::int64_t>, std::vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asInt64();});
}

template GetArrayElements<std::shared_ptr<std::int64_t>, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::int64_t>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<std::int64_t>, std::vector>& array) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template<>
GetArrayElements<std::shared_ptr<std::intmax_t>, std::vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::intmax_t>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<std::intmax_t>, std::vector>& array) const
{
	populateArray<std::shared_ptr<std::intmax_t>, std::vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asLargestInt();});
}

template GetArrayElements<std::shared_ptr<std::intmax_t>, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::intmax_t>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<std::intmax_t>, std::vector>& array) const;
#endif

} // namespace Accessor
} // namespace JXXON
