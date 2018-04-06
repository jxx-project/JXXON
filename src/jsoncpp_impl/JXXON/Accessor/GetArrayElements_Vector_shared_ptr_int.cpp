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
#include <Polymorphic/Vector.h>

namespace JXXON {
namespace Accessor {

template<>
GetArrayElements<std::shared_ptr<int>, Polymorphic::Vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<int>, Polymorphic::Vector>::operator()(Polymorphic::Vector<std::shared_ptr<int>>& array) const
{
	populateArray<std::shared_ptr<int>, Polymorphic::Vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asInt();});
}

template GetArrayElements<std::shared_ptr<int>, Polymorphic::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<int>, Polymorphic::Vector>::operator()(Polymorphic::Vector<std::shared_ptr<int>>& array) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template<>
GetArrayElements<std::shared_ptr<std::int64_t>, Polymorphic::Vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::int64_t>, Polymorphic::Vector>::operator()(Polymorphic::Vector<std::shared_ptr<std::int64_t>>& array) const
{
	populateArray<std::shared_ptr<std::int64_t>, Polymorphic::Vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asInt64();});
}

template GetArrayElements<std::shared_ptr<std::int64_t>, Polymorphic::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::int64_t>, Polymorphic::Vector>::operator()(Polymorphic::Vector<std::shared_ptr<std::int64_t>>& array) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template<>
GetArrayElements<std::shared_ptr<std::intmax_t>, Polymorphic::Vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::intmax_t>, Polymorphic::Vector>::operator()(Polymorphic::Vector<std::shared_ptr<std::intmax_t>>& array) const
{
	populateArray<std::shared_ptr<std::intmax_t>, Polymorphic::Vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asLargestInt();});
}

template GetArrayElements<std::shared_ptr<std::intmax_t>, Polymorphic::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::intmax_t>, Polymorphic::Vector>::operator()(Polymorphic::Vector<std::shared_ptr<std::intmax_t>>& array) const;
#endif

} // namespace Accessor
} // namespace JXXON
