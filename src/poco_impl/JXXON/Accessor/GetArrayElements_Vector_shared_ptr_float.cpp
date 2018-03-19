//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements_shared_ptr.tcc"
#include <cstdint>
#include <Polymorphic/Vector.h>

namespace JXXON {
namespace Accessor {

template GetArrayElements<std::shared_ptr<float>, Polymorphic::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<float>, Polymorphic::Vector>::operator()(Json::ArrayBase<std::shared_ptr<float>, Polymorphic::Vector>& array) const;

template GetArrayElements<std::shared_ptr<double>, Polymorphic::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<double>, Polymorphic::Vector>::operator()(Json::ArrayBase<std::shared_ptr<double>, Polymorphic::Vector>& array) const;

} // namespace Accessor
} // namespace JXXON
