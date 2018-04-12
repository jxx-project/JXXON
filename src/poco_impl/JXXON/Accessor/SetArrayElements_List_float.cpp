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

template SetArrayElements<float, Base::List>::SetArrayElements(Json& json);
template void SetArrayElements<float, Base::List>::operator()(const Base::List<float>& array);

template SetArrayElements<double, Base::List>::SetArrayElements(Json& json);
template void SetArrayElements<double, Base::List>::operator()(const Base::List<double>& array);

}} // namespace JXXON::Accessor
