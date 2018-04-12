//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/Vector.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetArrayElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetArrayElements<std::shared_ptr<float>, Base::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<float>, Base::Vector>::operator()(const Base::Vector<std::shared_ptr<float>>& array);

template SetArrayElements<std::shared_ptr<double>, Base::Vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<double>, Base::Vector>::operator()(const Base::Vector<std::shared_ptr<double>>& array);

}} // namespace JXXON::Accessor
