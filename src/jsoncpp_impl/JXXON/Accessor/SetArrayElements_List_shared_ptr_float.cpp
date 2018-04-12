//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/List.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetArrayElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetArrayElements<std::shared_ptr<float>, Base::List>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<float>, Base::List>::operator()(const Base::List<std::shared_ptr<float>>& array);

template SetArrayElements<std::shared_ptr<double>, Base::List>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<double>, Base::List>::operator()(const Base::List<std::shared_ptr<double>>& array);

}} // namespace JXXON::Accessor
