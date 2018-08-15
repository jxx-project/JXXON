//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {


#if (_SIZEOF_INT8_T + 0)
template GetMapElements<std::shared_ptr<std::int8_t>>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::int8_t>>::operator()(Json::MapType<std::shared_ptr<std::int8_t>>& map) const;
#endif

#if (_SIZEOF_INT16_T + 0)
template GetMapElements<std::shared_ptr<std::int16_t>>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::int16_t>>::operator()(Json::MapType<std::shared_ptr<std::int16_t>>& map) const;
#endif

#if (_SIZEOF_INT32_T + 0)
template GetMapElements<std::shared_ptr<std::int32_t>>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::int32_t>>::operator()(Json::MapType<std::shared_ptr<std::int32_t>>& map) const;
#endif

#if (_SIZEOF_INT64_T + 0)
template GetMapElements<std::shared_ptr<std::int64_t>>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::int64_t>>::operator()(Json::MapType<std::shared_ptr<std::int64_t>>& map) const;
#endif

#if (_SIZEOF_INTMAX_T + 0) && \
	!((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || \
	  (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
template GetMapElements<std::shared_ptr<std::intmax_t>>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::intmax_t>>::operator()(Json::MapType<std::shared_ptr<std::intmax_t>>& map) const;
#endif

}} // namespace JXXON::Accessor
