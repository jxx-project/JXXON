//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/UnorderedMap.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetMapElements<std::shared_ptr<float>, Base::UnorderedMap>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<float>, Base::UnorderedMap>::operator()(Base::UnorderedMap<std::shared_ptr<float>>& map) const
{
	populateMap<std::shared_ptr<float>, Base::UnorderedMap>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asFloat();});
}

template GetMapElements<std::shared_ptr<float>, Base::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<float>, Base::UnorderedMap>::operator()(Base::UnorderedMap<std::shared_ptr<float>>& map) const;

template<>
GetMapElements<std::shared_ptr<double>, Base::UnorderedMap>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<double>, Base::UnorderedMap>::operator()(Base::UnorderedMap<std::shared_ptr<double>>& map) const
{
	populateMap<std::shared_ptr<double>, Base::UnorderedMap>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asDouble();});
}

template GetMapElements<std::shared_ptr<double>, Base::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<double>, Base::UnorderedMap>::operator()(Base::UnorderedMap<std::shared_ptr<double>>& map) const;

}} // namespace JXXON::Accessor
