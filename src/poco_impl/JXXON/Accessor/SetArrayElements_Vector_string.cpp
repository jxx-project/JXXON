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
#include <Polymorphic/Vector.h>

namespace JXXON { namespace Accessor {

template SetArrayElements<std::string, Polymorphic::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::string, Polymorphic::Vector>::operator()(const Polymorphic::Vector<std::string>& array);

}} // namespace JXXON::Accessor
