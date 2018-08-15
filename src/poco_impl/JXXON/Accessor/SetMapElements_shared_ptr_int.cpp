//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/SetMapElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {


#if (_SIZEOF_INT8_T + 0)
template SetMapElements<std::shared_ptr<std::int8_t>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::int8_t>>::operator()(const Json::MapType<std::shared_ptr<std::int8_t>>& map);
#endif

#if (_SIZEOF_INT16_T + 0)
template SetMapElements<std::shared_ptr<std::int16_t>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::int16_t>>::operator()(const Json::MapType<std::shared_ptr<std::int16_t>>& map);
#endif

#if (_SIZEOF_INT32_T + 0)
template SetMapElements<std::shared_ptr<std::int32_t>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::int32_t>>::operator()(const Json::MapType<std::shared_ptr<std::int32_t>>& map);
#endif

#if (_SIZEOF_INT64_T + 0)
template SetMapElements<std::shared_ptr<std::int64_t>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::int64_t>>::operator()(const Json::MapType<std::shared_ptr<std::int64_t>>& map);
#endif

#if (_SIZEOF_INTMAX_T + 0) && \
	!((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || \
	  (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
template SetMapElements<std::shared_ptr<std::intmax_t>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::intmax_t>>::operator()(const Json::MapType<std::shared_ptr<std::intmax_t>>& map);
#endif

}} // namespace JXXON::Accessor
