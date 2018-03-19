//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetArrayElements_shared_ptr.tcc"
#include <cstdint>
#include <Polymorphic/List.h>

namespace JXXON {
namespace Accessor {

template SetArrayElements<std::shared_ptr<float>, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<float>, Polymorphic::List>::operator()(const Json::ArrayBase<std::shared_ptr<float>, Polymorphic::List>& array);

template SetArrayElements<std::shared_ptr<double>, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<double>, Polymorphic::List>::operator()(const Json::ArrayBase<std::shared_ptr<double>, Polymorphic::List>& array);

} // namespace Accessor
} // namespace JXXON
