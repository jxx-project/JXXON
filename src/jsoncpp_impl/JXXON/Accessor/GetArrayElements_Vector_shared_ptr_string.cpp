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

template<>
GetArrayElements<std::shared_ptr<std::string>, Base::Vector>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::string>, Base::Vector>::operator()(Base::Vector<std::shared_ptr<std::string>>& array) const
{
	populateArray<std::shared_ptr<std::string>, Base::Vector>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asString();});
}

template GetArrayElements<std::shared_ptr<std::string>, Base::Vector>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::string>, Base::Vector>::operator()(Base::Vector<std::shared_ptr<std::string>>& array) const;

}} // namespace JXXON::Accessor
