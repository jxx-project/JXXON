//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/Vector.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetArrayElements<int, Base::Vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<int, Base::Vector>::operator()(Base::Vector<int>& array) const
{
	populateArray<int, Base::Vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asInt();});
}

template GetArrayElements<int, Base::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<int, Base::Vector>::operator()(Base::Vector<int>& array) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template<>
GetArrayElements<std::int64_t, Base::Vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::int64_t, Base::Vector>::operator()(Base::Vector<std::int64_t>& array) const
{
	populateArray<std::int64_t, Base::Vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asInt64();});
}

template GetArrayElements<std::int64_t, Base::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::int64_t, Base::Vector>::operator()(Base::Vector<std::int64_t>& array) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template<>
GetArrayElements<std::intmax_t, Base::Vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::intmax_t, Base::Vector>::operator()(Base::Vector<std::intmax_t>& array) const
{
	populateArray<std::intmax_t, Base::Vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asLargestInt();});
}

template GetArrayElements<std::intmax_t, Base::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::intmax_t, Base::Vector>::operator()(Base::Vector<std::intmax_t>& array) const;
#endif

}} // namespace JXXON::Accessor
