//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {


#if (_SIZEOF_UINT8_T + 0)
template<>
GetArrayElements<std::shared_ptr<std::uint8_t>>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::uint8_t>>::operator()(Json::ArrayType<std::shared_ptr<std::uint8_t>>& array) const
{
	populateArray<std::shared_ptr<std::uint8_t>>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asUInt();});
}

template GetArrayElements<std::shared_ptr<std::uint8_t>>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::uint8_t>>::operator()(Json::ArrayType<std::shared_ptr<std::uint8_t>>& array) const;
#endif

#if (_SIZEOF_UINT16_T + 0)
template<>
GetArrayElements<std::shared_ptr<std::uint16_t>>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::uint16_t>>::operator()(Json::ArrayType<std::shared_ptr<std::uint16_t>>& array) const
{
	populateArray<std::shared_ptr<std::uint16_t>>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asUInt();});
}

template GetArrayElements<std::shared_ptr<std::uint16_t>>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::uint16_t>>::operator()(Json::ArrayType<std::shared_ptr<std::uint16_t>>& array) const;
#endif

#if (_SIZEOF_UINT32_T + 0)
template<>
GetArrayElements<std::shared_ptr<std::uint32_t>>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::uint32_t>>::operator()(Json::ArrayType<std::shared_ptr<std::uint32_t>>& array) const
{
	populateArray<std::shared_ptr<std::uint32_t>>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asUInt();});
}

template GetArrayElements<std::shared_ptr<std::uint32_t>>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::uint32_t>>::operator()(Json::ArrayType<std::shared_ptr<std::uint32_t>>& array) const;
#endif

#if (_SIZEOF_UINT64_T + 0)
template<>
GetArrayElements<std::shared_ptr<std::uint64_t>>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::uint64_t>>::operator()(Json::ArrayType<std::shared_ptr<std::uint64_t>>& array) const
{
	populateArray<std::shared_ptr<std::uint64_t>>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asUInt64();});
}

template GetArrayElements<std::shared_ptr<std::uint64_t>>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::uint64_t>>::operator()(Json::ArrayType<std::shared_ptr<std::uint64_t>>& array) const;
#endif

#if (_SIZEOF_UINTMAX_T + 0) && !((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
template<>
GetArrayElements<std::shared_ptr<std::uintmax_t>>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::uintmax_t>>::operator()(Json::ArrayType<std::shared_ptr<std::uintmax_t>>& array) const
{
	populateArray<std::shared_ptr<std::uintmax_t>>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asLargestUInt();});
}

template GetArrayElements<std::shared_ptr<std::uintmax_t>>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::uintmax_t>>::operator()(Json::ArrayType<std::shared_ptr<std::uintmax_t>>& array) const;
#endif

}} // namespace JXXON::Accessor
