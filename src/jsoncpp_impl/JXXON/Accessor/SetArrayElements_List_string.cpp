//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetArrayElements.tcc"
#include <cstdint>
#include <Polymorphic/List.h>

namespace JXXON { namespace Accessor {

template SetArrayElements<std::string, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<std::string, Polymorphic::List>::operator()(const Polymorphic::List<std::string>& array);

}} // namespace JXXON::Accessor
