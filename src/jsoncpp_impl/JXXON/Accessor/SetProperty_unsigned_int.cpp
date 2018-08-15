//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/SetProperty.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {


#if (_SIZEOF_UINT8_T + 0)
template SetProperty<std::uint8_t>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::uint8_t>::operator()(const std::uint8_t& value);
#endif

#if (_SIZEOF_UINT16_T + 0)
template SetProperty<std::uint16_t>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::uint16_t>::operator()(const std::uint16_t& value);
#endif

#if (_SIZEOF_UINT32_T + 0)
template SetProperty<std::uint32_t>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::uint32_t>::operator()(const std::uint32_t& value);
#endif

#if (_SIZEOF_UINT64_T + 0)
template SetProperty<std::uint64_t>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::uint64_t>::operator()(const std::uint64_t& value);
#endif

#if (_SIZEOF_UINTMAX_T + 0) && \
	!((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || \
	  (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
template SetProperty<std::uintmax_t>::SetProperty(Json& json, const std::string& name);
template void SetProperty<std::uintmax_t>::operator()(const std::uintmax_t& value);
#endif

}} // namespace JXXON::Accessor
