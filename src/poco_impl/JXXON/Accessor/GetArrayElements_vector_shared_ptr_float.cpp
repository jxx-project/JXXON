//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include "JXXON/Accessor/GetArrayElements_shared_ptr.tcc"
#include <cstdint>
#include <vector>

namespace JXXON {
namespace Accessor {

template GetArrayElements<std::shared_ptr<float>, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<float>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<float>, std::vector>& array) const;

template GetArrayElements<std::shared_ptr<double>, std::vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<double>, std::vector>::operator()(Json::ArrayBase<std::shared_ptr<double>, std::vector>& array) const;

} // namespace Accessor
} // namespace JXXON
