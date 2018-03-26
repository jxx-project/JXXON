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
#include <Polymorphic/List.h>

namespace JXXON {
namespace Accessor {

template GetArrayElements<std::shared_ptr<float>, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<float>, Polymorphic::List>::operator()(Json::ArrayBase<std::shared_ptr<float>, Polymorphic::List>& array) const;

template GetArrayElements<std::shared_ptr<double>, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<double>, Polymorphic::List>::operator()(Json::ArrayBase<std::shared_ptr<double>, Polymorphic::List>& array) const;

} // namespace Accessor
} // namespace JXXON