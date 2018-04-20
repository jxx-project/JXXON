//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {


#if (_SIZEOF_UINT8_T + 0)
template SetMapElements<std::shared_ptr<std::uint8_t>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::uint8_t>>::operator()(const Json::MapType<std::shared_ptr<std::uint8_t>>& map);
#endif

#if (_SIZEOF_UINT16_T + 0)
template SetMapElements<std::shared_ptr<std::uint16_t>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::uint16_t>>::operator()(const Json::MapType<std::shared_ptr<std::uint16_t>>& map);
#endif

#if (_SIZEOF_UINT32_T + 0)
template SetMapElements<std::shared_ptr<std::uint32_t>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::uint32_t>>::operator()(const Json::MapType<std::shared_ptr<std::uint32_t>>& map);
#endif

#if (_SIZEOF_UINT64_T + 0)
template SetMapElements<std::shared_ptr<std::uint64_t>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::uint64_t>>::operator()(const Json::MapType<std::shared_ptr<std::uint64_t>>& map);
#endif

#if (_SIZEOF_UINTMAX_T + 0) && !((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
template SetMapElements<std::shared_ptr<std::uintmax_t>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::uintmax_t>>::operator()(const Json::MapType<std::shared_ptr<std::uintmax_t>>& map);
#endif

}} // namespace JXXON::Accessor
