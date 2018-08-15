//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {


#if (_SIZEOF_INT8_T + 0)
template GetArrayElements<std::int8_t>::GetArrayElements(const Json& json);
template void GetArrayElements<std::int8_t>::operator()(Json::ArrayType<std::int8_t>& array) const;
#endif

#if (_SIZEOF_INT16_T + 0)
template GetArrayElements<std::int16_t>::GetArrayElements(const Json& json);
template void GetArrayElements<std::int16_t>::operator()(Json::ArrayType<std::int16_t>& array) const;
#endif

#if (_SIZEOF_INT32_T + 0)
template GetArrayElements<std::int32_t>::GetArrayElements(const Json& json);
template void GetArrayElements<std::int32_t>::operator()(Json::ArrayType<std::int32_t>& array) const;
#endif

#if (_SIZEOF_INT64_T + 0)
template GetArrayElements<std::int64_t>::GetArrayElements(const Json& json);
template void GetArrayElements<std::int64_t>::operator()(Json::ArrayType<std::int64_t>& array) const;
#endif

#if (_SIZEOF_INTMAX_T + 0) && \
	!((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || \
	  (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
template GetArrayElements<std::intmax_t>::GetArrayElements(const Json& json);
template void GetArrayElements<std::intmax_t>::operator()(Json::ArrayType<std::intmax_t>& array) const;
#endif

}} // namespace JXXON::Accessor
