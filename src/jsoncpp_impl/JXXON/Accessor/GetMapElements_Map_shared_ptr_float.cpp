//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>
#include <Polymorphic/Map.h>

namespace JXXON {
namespace Accessor {

template<>
GetMapElements<std::shared_ptr<float>, Polymorphic::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<float>, Polymorphic::Map>::operator()(Polymorphic::Map< std::string, std::shared_ptr<float> >& map) const
{
	populateMap<std::shared_ptr<float>, Polymorphic::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asFloat();});
}

template GetMapElements<std::shared_ptr<float>, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<float>, Polymorphic::Map>::operator()(Polymorphic::Map< std::string, std::shared_ptr<float> >& map) const;

template<>
GetMapElements<std::shared_ptr<double>, Polymorphic::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<double>, Polymorphic::Map>::operator()(Polymorphic::Map< std::string, std::shared_ptr<double> >& map) const
{
	populateMap<std::shared_ptr<double>, Polymorphic::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asDouble();});
}

template GetMapElements<std::shared_ptr<double>, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<double>, Polymorphic::Map>::operator()(Polymorphic::Map< std::string, std::shared_ptr<double> >& map) const;

} // namespace Accessor
} // namespace JXXON
