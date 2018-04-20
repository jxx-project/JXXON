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


#if (_SIZEOF_INT8_T + 0)
template GetArrayElements<std::shared_ptr<std::int8_t>>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::int8_t>>::operator()(Json::ArrayType<std::shared_ptr<std::int8_t>>& array) const;
#endif

#if (_SIZEOF_INT16_T + 0)
template GetArrayElements<std::shared_ptr<std::int16_t>>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::int16_t>>::operator()(Json::ArrayType<std::shared_ptr<std::int16_t>>& array) const;
#endif

#if (_SIZEOF_INT32_T + 0)
template GetArrayElements<std::shared_ptr<std::int32_t>>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::int32_t>>::operator()(Json::ArrayType<std::shared_ptr<std::int32_t>>& array) const;
#endif

#if (_SIZEOF_INT64_T + 0)
template GetArrayElements<std::shared_ptr<std::int64_t>>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::int64_t>>::operator()(Json::ArrayType<std::shared_ptr<std::int64_t>>& array) const;
#endif

#if (_SIZEOF_INTMAX_T + 0) && !((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
template GetArrayElements<std::shared_ptr<std::intmax_t>>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::intmax_t>>::operator()(Json::ArrayType<std::shared_ptr<std::intmax_t>>& array) const;
#endif

}} // namespace JXXON::Accessor
