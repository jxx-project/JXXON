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
GetArrayElements<unsigned int, Polymorphic::List>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<unsigned int, Polymorphic::List>::operator()(Polymorphic::List<unsigned int>& array) const
{
	populateArray<unsigned int, Polymorphic::List>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asUInt();});
}

template GetArrayElements<unsigned int, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<unsigned int, Polymorphic::List>::operator()(Polymorphic::List<unsigned int>& array) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template<>
GetArrayElements<std::uint64_t, Polymorphic::List>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::uint64_t, Polymorphic::List>::operator()(Polymorphic::List<std::uint64_t>& array) const
{
	populateArray<std::uint64_t, Polymorphic::List>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asUInt64();});
}

template GetArrayElements<std::uint64_t, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::uint64_t, Polymorphic::List>::operator()(Polymorphic::List<std::uint64_t>& array) const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template<>
GetArrayElements<std::uintmax_t, Polymorphic::List>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::uintmax_t, Polymorphic::List>::operator()(Polymorphic::List<std::uintmax_t>& array) const
{
	populateArray<std::uintmax_t, Polymorphic::List>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asLargestUInt();});
}

template GetArrayElements<std::uintmax_t, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::uintmax_t, Polymorphic::List>::operator()(Polymorphic::List<std::uintmax_t>& array) const;
#endif

} // namespace Accessor
} // namespace JXXON
