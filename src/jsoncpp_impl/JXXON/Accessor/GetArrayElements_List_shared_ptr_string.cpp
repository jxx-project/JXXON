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

template<>
GetArrayElements<std::shared_ptr<std::string>, Polymorphic::List>::GetArrayElements(const Json& json) : json(json)
{
}

template<>
void GetArrayElements<std::shared_ptr<std::string>, Polymorphic::List>::operator()(Polymorphic::List<std::shared_ptr<std::string>>& array) const
{
	populateArray<std::shared_ptr<std::string>, Polymorphic::List>(array, json.pimpl->value, [](const ::Json::Value& value){return value.asString();});
}

template GetArrayElements<std::shared_ptr<std::string>, Polymorphic::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::shared_ptr<std::string>, Polymorphic::List>::operator()(Polymorphic::List<std::shared_ptr<std::string>>& array) const;

} // namespace Accessor
} // namespace JXXON
