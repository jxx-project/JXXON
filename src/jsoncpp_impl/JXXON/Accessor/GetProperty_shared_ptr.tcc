//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Accessor_GetProperty_shared_ptr_INCLUDED
#define JXXON_Accessor_GetProperty_shared_ptr_INCLUDED

namespace JXXON { namespace Accessor {
namespace {

template<typename T>
T getChild(const ::Json::Value& value, const std::string& name, const std::function<typename T::element_type(const ::Json::Value&)>& valueAsT)
{
	if (!value.isNull()) {
		try {
			auto child = value.get(name, ::Json::Value::null);
			if (!child.isNull()) {
				return std::make_shared<typename T::element_type>(valueAsT(child));
			}
		} catch(std::exception& e) {
			throw Error(e.what());
		}
	}
	return nullptr;
}

} // namespace
}} // namespace JXXON::Accessor

#endif // JXXON_Accessor_GetProperty_shared_ptr_INCLUDED
