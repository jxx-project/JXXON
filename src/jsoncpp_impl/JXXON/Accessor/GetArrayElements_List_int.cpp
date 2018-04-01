//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>
#include <Polymorphic/List.h>

namespace JXXON {
namespace Accessor {

template<>
GetArrayElements<int, Polymorphic::List>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<int, Polymorphic::List>::operator()(Polymorphic::List<int>& array) const
{
	populateArray<int, Polymorphic::List>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asInt();});
}

template GetArrayElements<int, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<int, Polymorphic::List>::operator()(Polymorphic::List<int>& array) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template<>
GetArrayElements<std::int64_t, Polymorphic::List>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::int64_t, Polymorphic::List>::operator()(Polymorphic::List<std::int64_t>& array) const
{
	populateArray<std::int64_t, Polymorphic::List>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asInt64();});
}

template GetArrayElements<std::int64_t, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::int64_t, Polymorphic::List>::operator()(Polymorphic::List<std::int64_t>& array) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template<>
GetArrayElements<std::intmax_t, Polymorphic::List>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::intmax_t, Polymorphic::List>::operator()(Polymorphic::List<std::intmax_t>& array) const
{
	populateArray<std::intmax_t, Polymorphic::List>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asLargestInt();});
}

template GetArrayElements<std::intmax_t, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::intmax_t, Polymorphic::List>::operator()(Polymorphic::List<std::intmax_t>& array) const;
#endif

} // namespace Accessor
} // namespace JXXON
