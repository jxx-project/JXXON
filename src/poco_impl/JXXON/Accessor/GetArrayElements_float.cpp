//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template GetArrayElements<float>::GetArrayElements(const Json& json);
template void GetArrayElements<float>::operator()(Json::ArrayType<float>& array) const;

template GetArrayElements<double>::GetArrayElements(const Json& json);
template void GetArrayElements<double>::operator()(Json::ArrayType<double>& array) const;

}} // namespace JXXON::Accessor
