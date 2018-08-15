//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/SetArrayElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {


#if (_SIZEOF_UINT8_T + 0)
template SetArrayElements<std::shared_ptr<std::uint8_t>>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<std::uint8_t>>::operator()(const Json::ArrayType<std::shared_ptr<std::uint8_t>>& array);
#endif

#if (_SIZEOF_UINT16_T + 0)
template SetArrayElements<std::shared_ptr<std::uint16_t>>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<std::uint16_t>>::operator()(const Json::ArrayType<std::shared_ptr<std::uint16_t>>& array);
#endif

#if (_SIZEOF_UINT32_T + 0)
template SetArrayElements<std::shared_ptr<std::uint32_t>>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<std::uint32_t>>::operator()(const Json::ArrayType<std::shared_ptr<std::uint32_t>>& array);
#endif

#if (_SIZEOF_UINT64_T + 0)
template SetArrayElements<std::shared_ptr<std::uint64_t>>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<std::uint64_t>>::operator()(const Json::ArrayType<std::shared_ptr<std::uint64_t>>& array);
#endif

#if (_SIZEOF_UINTMAX_T + 0) && \
	!((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || \
	  (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
template SetArrayElements<std::shared_ptr<std::uintmax_t>>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<std::uintmax_t>>::operator()(const Json::ArrayType<std::shared_ptr<std::uintmax_t>>& array);
#endif

}} // namespace JXXON::Accessor
