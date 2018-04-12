//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/List.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetArrayElements<std::string, Base::List>::SetArrayElements(Json& json);
template void SetArrayElements<std::string, Base::List>::operator()(const Base::List<std::string>& array);

}} // namespace JXXON::Accessor
