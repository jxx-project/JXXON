//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetProperty_shared_ptr.hpp"
#include <cstdint>

namespace JXXON {
namespace Accessor {

template GetProperty< std::shared_ptr<float> >::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<float> GetProperty< std::shared_ptr<float> >::operator()() const;

template GetProperty< std::shared_ptr<double> >::GetProperty(const Json& json, const std::string& name);
template std::shared_ptr<double> GetProperty< std::shared_ptr<double> >::operator()() const;

} // namespace Accessor
} // namespace JXXON
