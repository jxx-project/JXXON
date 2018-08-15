//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/SetProperty.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {


#if (_SIZEOF_INT8_T + 0)
template SetProperty<std::int8_t>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::int8_t>::operator()(const std::int8_t& value);
#endif

#if (_SIZEOF_INT16_T + 0)
template SetProperty<std::int16_t>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::int16_t>::operator()(const std::int16_t& value);
#endif

#if (_SIZEOF_INT32_T + 0)
template SetProperty<std::int32_t>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::int32_t>::operator()(const std::int32_t& value);
#endif

#if (_SIZEOF_INT64_T + 0)
template SetProperty<std::int64_t>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::int64_t>::operator()(const std::int64_t& value);
#endif

#if (_SIZEOF_INTMAX_T + 0) && \
	!((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || \
	  (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
template SetProperty<std::intmax_t>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::intmax_t>::operator()(const std::intmax_t& value);
#endif

}} // namespace JXXON::Accessor
