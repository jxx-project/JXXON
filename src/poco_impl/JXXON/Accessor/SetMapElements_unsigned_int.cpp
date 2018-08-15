//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/SetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {


#if (_SIZEOF_UINT8_T + 0)
template SetMapElements<std::uint8_t>::SetMapElements(Json& json);
template void SetMapElements<std::uint8_t>::operator()(const Json::MapType<std::uint8_t>& map);
#endif

#if (_SIZEOF_UINT16_T + 0)
template SetMapElements<std::uint16_t>::SetMapElements(Json& json);
template void SetMapElements<std::uint16_t>::operator()(const Json::MapType<std::uint16_t>& map);
#endif

#if (_SIZEOF_UINT32_T + 0)
template SetMapElements<std::uint32_t>::SetMapElements(Json& json);
template void SetMapElements<std::uint32_t>::operator()(const Json::MapType<std::uint32_t>& map);
#endif

#if (_SIZEOF_UINT64_T + 0)
template SetMapElements<std::uint64_t>::SetMapElements(Json& json);
template void SetMapElements<std::uint64_t>::operator()(const Json::MapType<std::uint64_t>& map);
#endif

#if (_SIZEOF_UINTMAX_T + 0) && \
	!((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || \
	  (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
template SetMapElements<std::uintmax_t>::SetMapElements(Json& json);
template void SetMapElements<std::uintmax_t>::operator()(const Json::MapType<std::uintmax_t>& map);
#endif

}} // namespace JXXON::Accessor
