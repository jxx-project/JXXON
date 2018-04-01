//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>
#include <Polymorphic/Vector.h>

namespace JXXON {
namespace Accessor {

template GetArrayElements<float, Polymorphic::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<float, Polymorphic::Vector>::operator()(Polymorphic::Vector<float>& array) const;

template GetArrayElements<double, Polymorphic::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<double, Polymorphic::Vector>::operator()(Polymorphic::Vector<double>& array) const;

} // namespace Accessor
} // namespace JXXON
