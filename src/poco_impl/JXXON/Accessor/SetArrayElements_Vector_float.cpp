//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/Vector.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetArrayElements<float, Base::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<float, Base::Vector>::operator()(const Base::Vector<float>& array);

template SetArrayElements<double, Base::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<double, Base::Vector>::operator()(const Base::Vector<double>& array);

}} // namespace JXXON::Accessor
