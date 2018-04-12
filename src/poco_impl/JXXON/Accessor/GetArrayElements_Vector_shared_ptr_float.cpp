//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/Vector.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template GetArrayElements<std::shared_ptr<float>, Base::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<float>, Base::Vector>::operator()(Base::Vector<std::shared_ptr<float>>& array) const;

template GetArrayElements<std::shared_ptr<double>, Base::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<double>, Base::Vector>::operator()(Base::Vector<std::shared_ptr<double>>& array) const;

}} // namespace JXXON::Accessor
