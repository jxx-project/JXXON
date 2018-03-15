//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include "JXXON/Accessor/GetProperty.tcc"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template GetProperty<float>::GetProperty(const Json& json, const std::string& name);
template float GetProperty<float>::operator()() const;

template GetProperty<double>::GetProperty(const Json& json, const std::string& name);
template double GetProperty<double>::operator()() const;

} // namespace Accessor
} // namespace JXXON
