//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetArrayElements_shared_ptr.hpp"
#include <list>

namespace JXXON {
namespace Accessor {

template<>
GetArrayElements<std::shared_ptr<int>, std::list>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<int>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<int>, std::list>& array) const
{
	populateArray<std::shared_ptr<int>, std::list>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt();});
}

template GetArrayElements<std::shared_ptr<int>, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<int>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<int>, std::list>& array) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template<>
GetArrayElements<std::shared_ptr<std::int64_t>, std::list>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::int64_t>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<std::int64_t>, std::list>& array) const
{
	populateArray<std::shared_ptr<std::int64_t>, std::list>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asInt64();});
}

template GetArrayElements<std::shared_ptr<std::int64_t>, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::int64_t>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<std::int64_t>, std::list>& array) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template<>
GetArrayElements<std::shared_ptr<std::intmax_t>, std::list>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::intmax_t>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<std::intmax_t>, std::list>& array) const
{
	populateArray<std::shared_ptr<std::intmax_t>, std::list>(array, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asLargestInt();});
}

template GetArrayElements<std::shared_ptr<std::intmax_t>, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::intmax_t>, std::list>::operator()(Json::ArrayBase<std::shared_ptr<std::intmax_t>, std::list>& array) const;
#endif

} // namespace Accessor
} // namespace JXXON
