//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/List.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template GetArrayElements<float, Base::List>::GetArrayElements(const Json& json);
template void GetArrayElements<float, Base::List>::operator()(Base::List<float>& array) const;

template GetArrayElements<double, Base::List>::GetArrayElements(const Json& json);
template void GetArrayElements<double, Base::List>::operator()(Base::List<double>& array) const;

}} // namespace JXXON::Accessor
