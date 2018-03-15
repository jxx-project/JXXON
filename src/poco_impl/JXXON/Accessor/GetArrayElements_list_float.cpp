//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>
#include <list>

namespace JXXON {
namespace Accessor {

template GetArrayElements<float, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<float, std::list>::operator()(Json::ArrayBase<float, std::list>& array) const;

template GetArrayElements<double, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<double, std::list>::operator()(Json::ArrayBase<double, std::list>& array) const;

} // namespace Accessor
} // namespace JXXON
