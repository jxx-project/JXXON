//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE JXXON
#include <boost/test/unit_test.hpp>

#include "Model/NullableStringObject.h"
#include "Model/NullableIntObject.h"
#include "Model/NullableUIntObject.h"
#include "Model/NullableInt64Object.h"
#include "Model/NullableUInt64Object.h"
#include "Model/NullableIntMaxObject.h"
#include "Model/NullableUIntMaxObject.h"
#include "Model/NullableFloatObject.h"
#include "Model/NullableDoubleObject.h"
#include "Model/NullableBoolObject.h"
#include "Model/NullableNestedObject.h"
#include "Model/NullableVectorOfStringObject.h"
#include "Model/NullableListOfStringObject.h"
#include "JXXON/Error.h"
#include "JXXON/Vector.h"
#include "JXXON/List.h"
#include "JXXON/Map.h"
#include "JXXON/UnorderedMap.h"

BOOST_AUTO_TEST_CASE( NullableStringObject )
{
	static const std::string JSON_IN("{\"value\":\"dummy\"}");
	JXXON::Json json(JSON_IN);
	Model::NullableStringObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyStringObject )
{
	static const std::string JSON_IN("{}");
	JXXON::Json json(JSON_IN);
	Model::NullableStringObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidStringObject )
{
	static const std::string JSON_IN("{\"value\":{\"inner\":\"dummy\"}}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::NullableStringObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableIntObject )
{
	static const std::string JSON_IN("{\"value\":-4711}");
	JXXON::Json json(JSON_IN);
	Model::NullableIntObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidIntObject )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::NullableIntObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableUIntObject )
{
	static const std::string JSON_IN("{\"value\":4711}");
	JXXON::Json json(JSON_IN);
	Model::NullableUIntObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidUIntObject )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::NullableUIntObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableInt64Object )
{
	static const std::string JSON_IN("{\"value\":-4711471147114711}");
	JXXON::Json json(JSON_IN);
	Model::NullableInt64Object object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidInt64Object )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::NullableInt64Object object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableUInt64Object )
{
	static const std::string JSON_IN("{\"value\":4711471147114711}");
	JXXON::Json json(JSON_IN);
	Model::NullableUInt64Object object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidUInt64Object )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::NullableUInt64Object object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableIntMaxObject )
{
	static const std::string JSON_IN("{\"value\":-4711471147114711}");
	JXXON::Json json(JSON_IN);
	Model::NullableIntMaxObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidIntMaxObject )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::NullableIntMaxObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableUIntMaxObject )
{
	static const std::string JSON_IN("{\"value\":4711471147114711}");
	JXXON::Json json(JSON_IN);
	Model::NullableUIntMaxObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidUIntMaxObject )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::NullableUIntMaxObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableFloatObject )
{
	static const std::string JSON_IN("{\"value\":3.25}");
	JXXON::Json json(JSON_IN);
	Model::NullableFloatObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidFloatObject )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::NullableFloatObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableDoubleObject )
{
	static const std::string JSON_IN("{\"value\":3.25}");
	JXXON::Json json(JSON_IN);
	Model::NullableDoubleObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidDoubleObject )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::NullableDoubleObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableBoolObject )
{
	static const std::string JSON_IN("{\"value\":false}");
	JXXON::Json json(JSON_IN);
	Model::NullableBoolObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidBoolObject )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::NullableBoolObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableNestedObject )
{
	static const std::string JSON_IN("{\"outer\":{\"value\":\"dummy\"}}");
	JXXON::Json json(JSON_IN);
	Model::NullableNestedObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyNestedObject )
{
	static const std::string JSON_IN("{}");
	JXXON::Json json(JSON_IN);
	Model::NullableNestedObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidNestedObject )
{
	static const std::string JSON_IN("{\"outer\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::NullableNestedObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ArrayAsNestedObject )
{
	static const std::string JSON_IN("[{\"outer\":{\"value\":\"dummy\"}}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::NullableNestedObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableVectorOfObject )
{
	static const std::string JSON_IN("[{\"value\":\"dummy1\"},{\"value\":\"dummy2\"}]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<Model::NullableStringObject> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyNullableVectorOfObject )
{
	static const std::string JSON_IN("[]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<Model::NullableStringObject> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfInvalidObject )
{
	static const std::string JSON_IN("[\"invalid\"]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::shared_ptr<Model::NullableStringObject> > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ObjectAsNullableVectorOfObject )
{
	static const std::string JSON_IN("{\"value\":[{\"value\":\"dummy1\"},{\"value\":\"dummy2\"}]}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::shared_ptr<Model::NullableStringObject> > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableVectorOfObjectWithNull )
{
	static const std::string JSON_IN("[{\"value\":\"dummy1\"},{\"value\":\"dummy2\"},null]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<Model::NullableStringObject> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfString )
{
	static const std::string JSON_IN("[\"dummy1\",\"dummy2\"]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<std::string> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyNullableVectorOfString )
{
	static const std::string JSON_IN("[]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<std::string> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfInvalidString )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::shared_ptr<std::string> > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ObjectAsNullableVectorOfString )
{
	static const std::string JSON_IN("{\"value\":[\"dummy1\",\"dummy2\"]}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::shared_ptr<std::string> > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableVectorOfStringWithNull )
{
	static const std::string JSON_IN("[\"dummy1\",\"dummy2\",null]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<std::string> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfInt )
{
	static const std::string JSON_IN("[-4711,-4712]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<int> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfInvalidInt )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::shared_ptr<int> > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableVectorOfIntWithNull )
{
	static const std::string JSON_IN("[-4711,-4712,null]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<int> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfUInt )
{
	static const std::string JSON_IN("[4711,4712]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<unsigned int> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfInvalidUInt )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::shared_ptr<unsigned int> > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableVectorOfUIntWithNull )
{
	static const std::string JSON_IN("[4711,4712,null]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<unsigned int> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfInt64 )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<std::int64_t> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfInvalidInt64 )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::shared_ptr<std::int64_t> > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableVectorOfInt64WithNull )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712,null]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<std::int64_t> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfUInt64 )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<std::uint64_t> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfInvalidUInt64 )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::shared_ptr<std::uint64_t> > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableVectorOfUInt64WithNull )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712,null]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<std::uint64_t> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfIntMax )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<std::intmax_t> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfInvalidIntMax )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::shared_ptr<std::intmax_t> > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableVectorOfIntMaxWithNull )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712,null]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<std::intmax_t> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfUIntMax )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<std::uintmax_t> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfInvalidUIntMax )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::shared_ptr<std::uintmax_t> > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableVectorOfUIntMaxWithNull )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712,null]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<std::uintmax_t> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfFloat )
{
	static const std::string JSON_IN("[3.25,6.75]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<float> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfInvalidFloat )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::shared_ptr<float> > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableVectorOfFloatWithNull )
{
	static const std::string JSON_IN("[3.25,6.75,null]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<float> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfDouble )
{
	static const std::string JSON_IN("[3.25,6.75]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<double> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfInvalidDouble )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::shared_ptr<double> > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableVectorOfDoubleWithNull )
{
	static const std::string JSON_IN("[3.25,6.75,null]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<double> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfBool )
{
	static const std::string JSON_IN("[true,false]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<bool> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfInvalidBool )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::shared_ptr<bool> > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableVectorOfBoolWithNull )
{
	static const std::string JSON_IN("[true,false,null]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr<bool> > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NestedNullableVectorOfString )
{
	static const std::string JSON_IN("[[\"dummy1\",\"dummy2\"],[\"dummy3\",\"dummy4\"]]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr< JXXON::Vector< std::shared_ptr<std::string> > > > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidNestedNullableVectorOfString )
{
	static const std::string JSON_IN("[\"invalid\"]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::shared_ptr< JXXON::Vector< std::shared_ptr<std::string> > > > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NestedNullableVectorOfStringWithNull )
{
	static const std::string JSON_IN("[[\"dummy1\",\"dummy2\"],[\"dummy3\",\"dummy4\"],null]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::shared_ptr< JXXON::Vector< std::shared_ptr<std::string> > > > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableVectorOfStringObject )
{
	static const std::string JSON_IN("{\"value\":[\"dummy1\",\"dummy2\"]}");
	JXXON::Json json(JSON_IN);
	Model::NullableVectorOfStringObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfObject )
{
	static const std::string JSON_IN("[{\"value\":\"dummy1\"},{\"value\":\"dummy2\"}]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<Model::NullableStringObject> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyNullableListOfObject )
{
	static const std::string JSON_IN("[]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<Model::NullableStringObject> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfInvalidObject )
{
	static const std::string JSON_IN("[\"invalid\"]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::shared_ptr<Model::NullableStringObject> > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ObjectAsNullableListOfObject )
{
	static const std::string JSON_IN("{\"value\":[{\"value\":\"dummy1\"},{\"value\":\"dummy2\"}]}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::shared_ptr<Model::NullableStringObject> > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableListOfObjectWithNull )
{
	static const std::string JSON_IN("[{\"value\":\"dummy1\"},{\"value\":\"dummy2\"},null]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<Model::NullableStringObject> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfString )
{
	static const std::string JSON_IN("[\"dummy1\",\"dummy2\"]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<std::string> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyNullableListOfString )
{
	static const std::string JSON_IN("[]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<std::string> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfInvalidString )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::shared_ptr<std::string> > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ObjectAsNullableListOfString )
{
	static const std::string JSON_IN("{\"value\":[\"dummy1\",\"dummy2\"]}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::shared_ptr<std::string> > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableListOfStringWithNull )
{
	static const std::string JSON_IN("[\"dummy1\",\"dummy2\",null]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<std::string> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfInt )
{
	static const std::string JSON_IN("[-4711,-4712]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<int> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfInvalidInt )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::shared_ptr<int> > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableListOfIntWithNull )
{
	static const std::string JSON_IN("[-4711,-4712,null]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<int> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfUInt )
{
	static const std::string JSON_IN("[4711,4712]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<unsigned int> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfInvalidUInt )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::shared_ptr<unsigned int> > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableListOfUIntWithNull )
{
	static const std::string JSON_IN("[4711,4712,null]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<unsigned int> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfInt64 )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<std::int64_t> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfInvalidInt64 )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::shared_ptr<std::int64_t> > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableListOfInt64WithNull )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712,null]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<std::int64_t> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfUInt64 )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<std::uint64_t> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfInvalidUInt64 )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::shared_ptr<std::uint64_t> > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableListOfUInt64WithNull )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712,null]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<std::uint64_t> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfIntMax )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<std::intmax_t> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfInvalidIntMax )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::shared_ptr<std::intmax_t> > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableListOfIntMaxWithNull )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712,null]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<std::intmax_t> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfUIntMax )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<std::uintmax_t> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfInvalidUIntMax )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::shared_ptr<std::uintmax_t> > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableListOfUIntMaxWithNull )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712,null]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<std::uintmax_t> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfFloat )
{
	static const std::string JSON_IN("[3.25,6.75]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<float> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfInvalidFloat )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::shared_ptr<float> > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableListOfFloatWithNull )
{
	static const std::string JSON_IN("[3.25,6.75,null]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<float> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfDouble )
{
	static const std::string JSON_IN("[3.25,6.75]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<double> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfInvalidDouble )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::shared_ptr<double> > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableListOfDoubleWithNull )
{
	static const std::string JSON_IN("[3.25,6.75,null]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<double> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfBool )
{
	static const std::string JSON_IN("[true,false]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<bool> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfInvalidBool )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::shared_ptr<bool> > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullableListOfBoolWithNull )
{
	static const std::string JSON_IN("[true,false,null]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr<bool> > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NestedNullableListOfString )
{
	static const std::string JSON_IN("[[\"dummy1\",\"dummy2\"],[\"dummy3\",\"dummy4\"]]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr< JXXON::List< std::shared_ptr<std::string> > > > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidNestedNullableListOfString )
{
	static const std::string JSON_IN("[\"invalid\"]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::shared_ptr< JXXON::List< std::shared_ptr<std::string> > > > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NestedNullableListOfStringWithNull )
{
	static const std::string JSON_IN("[[\"dummy1\",\"dummy2\"],[\"dummy3\",\"dummy4\"],null]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::shared_ptr< JXXON::List< std::shared_ptr<std::string> > > > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NullableListOfStringObject )
{
	static const std::string JSON_IN("{\"value\":[\"dummy1\",\"dummy2\"]}");
	JXXON::Json json(JSON_IN);
	Model::NullableListOfStringObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( StringNullableMap )
{
	static const std::string JSON_IN("{\"value\":\"dummy\"}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::shared_ptr<std::string> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyStringNullableMap )
{
	static const std::string JSON_IN("{}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::shared_ptr<std::string> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( StringNullableMapWithNull )
{
	JXXON::Map< std::shared_ptr<std::string> > in;
	in.emplace("value1", std::shared_ptr<std::string>(new std::string("dummy1")));
	in.emplace("value2", std::shared_ptr<std::string>(new std::string("dummy2")));
	in.emplace("value3", std::shared_ptr<std::string>(nullptr));
	JXXON::Map< std::shared_ptr<std::string> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidStringNullableMap )
{
	static const std::string JSON_IN("{\"value\":{\"inner\":\"dummy\"}}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::shared_ptr<std::string> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( IntNullableMap )
{
	static const std::string JSON_IN("{\"value\":-4711}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::shared_ptr<int> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( IntNullableMapWithNull )
{
	JXXON::Map< std::shared_ptr<int> > in;
	in.emplace("value1", std::shared_ptr<int>(new int(-4711)));
	in.emplace("value2", std::shared_ptr<int>(new int(4711)));
	in.emplace("value3", std::shared_ptr<int>(nullptr));
	JXXON::Map< std::shared_ptr<int> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidIntNullableMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::shared_ptr<int> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( UIntNullableMap )
{
	static const std::string JSON_IN("{\"value\":4711}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::shared_ptr<unsigned int> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( UIntNullableMapWithNull )
{
	JXXON::Map< std::shared_ptr<unsigned int> > in;
	in.emplace("value1", std::shared_ptr<unsigned int>(new unsigned int(4711)));
	in.emplace("value2", std::shared_ptr<unsigned int>(new unsigned int(4712)));
	in.emplace("value3", std::shared_ptr<unsigned int>(nullptr));
	JXXON::Map< std::shared_ptr<unsigned int> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidUIntNullableMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::shared_ptr<unsigned int> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( Int64NullableMap )
{
	static const std::string JSON_IN("{\"value\":-4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::shared_ptr<std::int64_t> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( Int64NullableMapWithNull )
{
	JXXON::Map< std::shared_ptr<std::int64_t> > in;
	in.emplace("value1", std::shared_ptr<std::int64_t>(new std::int64_t(-4711471147114711)));
	in.emplace("value2", std::shared_ptr<std::int64_t>(new std::int64_t(4711471147114711)));
	in.emplace("value3", std::shared_ptr<std::int64_t>(nullptr));
	JXXON::Map< std::shared_ptr<std::int64_t> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidInt64NullableMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::shared_ptr<std::int64_t> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( UInt64NullableMap )
{
	static const std::string JSON_IN("{\"value\":4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::shared_ptr<std::uint64_t> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( UInt64NullableMapWithNull )
{
	JXXON::Map< std::shared_ptr<std::uint64_t> > in;
	in.emplace("value1", std::shared_ptr<std::uint64_t>(new std::uint64_t(4711471147114711)));
	in.emplace("value2", std::shared_ptr<std::uint64_t>(new std::uint64_t(4712471247124712)));
	in.emplace("value3", std::shared_ptr<std::uint64_t>(nullptr));
	JXXON::Map< std::shared_ptr<std::uint64_t> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidUInt64NullableMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::shared_ptr<std::uint64_t> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( IntMaxNullableMap )
{
	static const std::string JSON_IN("{\"value\":-4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::shared_ptr<std::intmax_t> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( IntMaxNullableMapWithNull )
{
	JXXON::Map< std::shared_ptr<std::intmax_t> > in;
	in.emplace("value1", std::shared_ptr<std::intmax_t>(new std::intmax_t(-4711471147114711)));
	in.emplace("value2", std::shared_ptr<std::intmax_t>(new std::intmax_t(4711471147114711)));
	in.emplace("value3", std::shared_ptr<std::intmax_t>(nullptr));
	JXXON::Map< std::shared_ptr<std::intmax_t> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidIntMaxNullableMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::shared_ptr<std::intmax_t> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( UIntMaxNullableMap )
{
	static const std::string JSON_IN("{\"value\":4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::shared_ptr<std::uintmax_t> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( UIntMaxNullableMapWithNull )
{
	JXXON::Map< std::shared_ptr<std::uintmax_t> > in;
	in.emplace("value1", std::shared_ptr<std::uintmax_t>(new std::uintmax_t(4711471147114711)));
	in.emplace("value2", std::shared_ptr<std::uintmax_t>(new std::uintmax_t(4712471247124712)));
	in.emplace("value3", std::shared_ptr<std::uintmax_t>(nullptr));
	JXXON::Map< std::shared_ptr<std::uintmax_t> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidUIntMaxNullableMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::shared_ptr<std::uintmax_t> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( FloatNullableMap )
{
	static const std::string JSON_IN("{\"value\":3.25}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::shared_ptr<float> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( FloatNullableMapWithNull )
{
	JXXON::Map< std::shared_ptr<float> > in;
	in.emplace("value1", std::shared_ptr<float>(new float(3.25)));
	in.emplace("value2", std::shared_ptr<float>(new float(3.75)));
	in.emplace("value3", std::shared_ptr<float>(nullptr));
	JXXON::Map< std::shared_ptr<float> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidFloatNullableMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::shared_ptr<float> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( DoubleNullableMap )
{
	static const std::string JSON_IN("{\"value\":3.25}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::shared_ptr<double> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( DoubleNullableMapWithNull )
{
	JXXON::Map< std::shared_ptr<double> > in;
	in.emplace("value1", std::shared_ptr<double>(new double(3.25)));
	in.emplace("value2", std::shared_ptr<double>(new double(3.75)));
	in.emplace("value3", std::shared_ptr<double>(nullptr));
	JXXON::Map< std::shared_ptr<double> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidDoubleNullableMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::shared_ptr<double> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( BoolNullableMap )
{
	static const std::string JSON_IN("{\"value\":false}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::shared_ptr<bool> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( BoolNullableMapWithNull )
{
	JXXON::Map< std::shared_ptr<bool> > in;
	in.emplace("value1", std::shared_ptr<bool>(new bool(true)));
	in.emplace("value2", std::shared_ptr<bool>(new bool(false)));
	in.emplace("value3", std::shared_ptr<bool>(nullptr));
	JXXON::Map< std::shared_ptr<bool> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidBoolNullableMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::shared_ptr<bool> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NestedNullableMap )
{
	static const std::string JSON_IN("{\"outer\":{\"value\":\"dummy\"}}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::shared_ptr< JXXON::Map< std::shared_ptr<std::string> > > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyNestedNullableMap )
{
	static const std::string JSON_IN("{}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::shared_ptr< JXXON::Map< std::shared_ptr<std::string> > > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NestedNullableMapWithNull )
{
	JXXON::Map< std::shared_ptr< JXXON::Map<std::shared_ptr< std::string> > > > in;
	in.emplace("value1", std::shared_ptr< JXXON::Map< std::shared_ptr<std::string> > >(new JXXON::Map<std::shared_ptr< std::string> >()));
	in["value1"]->emplace("inner1", std::shared_ptr<std::string>(new std::string("dummy1")));
	in.emplace("value2", std::shared_ptr< JXXON::Map< std::shared_ptr<std::string> > >(new JXXON::Map<std::shared_ptr< std::string> >()));
	in["value2"]->emplace("inner2", std::shared_ptr<std::string>(new std::string("dummy2")));
	in.emplace("value3", std::shared_ptr< JXXON::Map< std::shared_ptr< std::string> > >(nullptr));
	JXXON::Map< std::shared_ptr< JXXON::Map<std::shared_ptr< std::string> > > > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out.at("value1")->at("inner1"), *in.at("value1")->at("inner1") );
	BOOST_CHECK_EQUAL( *out.at("value2")->at("inner2"), *in.at("value2")->at("inner2") );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidNestedNullableMapString )
{
	static const std::string JSON_IN("{\"outer\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::shared_ptr< JXXON::Map< std::shared_ptr<std::string> > > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( InvalidNestedNullableMapArray )
{
	static const std::string JSON_IN("{\"outer\":[\"invalid\"]}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::shared_ptr< JXXON::Map< std::shared_ptr<std::string> > > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ArrayAsNestedNullableMap )
{
	static const std::string JSON_IN("[{\"outer\":{\"value\":\"dummy\"}}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::shared_ptr< JXXON::Map< std::shared_ptr<std::string> > > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( VectorNullableMap )
{
	static const std::string JSON_IN("{\"value\":[\"dummy\"]}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::shared_ptr< JXXON::Vector< std::shared_ptr<std::string> > > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyVectorNullableMap )
{
	static const std::string JSON_IN("{}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::shared_ptr< JXXON::Vector< std::shared_ptr<std::string> > > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( VectorNullableMapWithNull )
{
	JXXON::Map< std::shared_ptr< JXXON::Vector< std::shared_ptr<std::string> > > > in;
	in.emplace("value1", std::shared_ptr< JXXON::Vector< std::shared_ptr<std::string> > >(new JXXON::Vector< std::shared_ptr<std::string> >()));
	in["value1"]->emplace_back(std::shared_ptr<std::string>(new std::string("dummy1")));
	in.emplace("value2", std::shared_ptr< JXXON::Vector< std::shared_ptr<std::string> > >(new JXXON::Vector< std::shared_ptr<std::string> >()));
	in["value2"]->emplace_back(std::shared_ptr<std::string>(new std::string("dummy2")));
	in.emplace("value3", std::shared_ptr< JXXON::Vector< std::shared_ptr<std::string> > >(nullptr));
	JXXON::Map< std::shared_ptr< JXXON::Vector< std::shared_ptr<std::string> > > > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out.at("value1")->at(0), *in.at("value1")->at(0) );
	BOOST_CHECK_EQUAL( *out.at("value2")->at(0), *in.at("value2")->at(0) );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidVectorNullableMapString )
{
	static const std::string JSON_IN("{\"outer\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::shared_ptr< JXXON::Vector< std::shared_ptr<std::string> > > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( InvalidVectorNullableMapObject )
{
	static const std::string JSON_IN("{\"outer\":{\"inner\":\"invalid\"}}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::shared_ptr< JXXON::Vector< std::shared_ptr<std::string> > > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( StringNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"dummy\"}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::shared_ptr<std::string> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyStringNullableUnorderedMap )
{
	static const std::string JSON_IN("{}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::shared_ptr<std::string> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( StringNullableUnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::shared_ptr<std::string> > in;
	in.emplace("value1", std::shared_ptr<std::string>(new std::string("dummy1")));
	in.emplace("value2", std::shared_ptr<std::string>(new std::string("dummy2")));
	in.emplace("value3", std::shared_ptr<std::string>(nullptr));
	JXXON::UnorderedMap< std::shared_ptr<std::string> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidStringNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":{\"inner\":\"dummy\"}}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::shared_ptr<std::string> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( IntNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":-4711}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::shared_ptr<int> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( IntNullableUnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::shared_ptr<int> > in;
	in.emplace("value1", std::shared_ptr<int>(new int(-4711)));
	in.emplace("value2", std::shared_ptr<int>(new int(4711)));
	in.emplace("value3", std::shared_ptr<int>(nullptr));
	JXXON::UnorderedMap< std::shared_ptr<int> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidIntNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::shared_ptr<int> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( UIntNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":4711}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::shared_ptr<unsigned int> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( UIntNullableUnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::shared_ptr<unsigned int> > in;
	in.emplace("value1", std::shared_ptr<unsigned int>(new unsigned int(4711)));
	in.emplace("value2", std::shared_ptr<unsigned int>(new unsigned int(4712)));
	in.emplace("value3", std::shared_ptr<unsigned int>(nullptr));
	JXXON::UnorderedMap< std::shared_ptr<unsigned int> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidUIntNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::shared_ptr<unsigned int> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( Int64NullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":-4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::shared_ptr<std::int64_t> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( Int64NullableUnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::shared_ptr<std::int64_t> > in;
	in.emplace("value1", std::shared_ptr<std::int64_t>(new std::int64_t(-4711471147114711)));
	in.emplace("value2", std::shared_ptr<std::int64_t>(new std::int64_t(4711471147114711)));
	in.emplace("value3", std::shared_ptr<std::int64_t>(nullptr));
	JXXON::UnorderedMap< std::shared_ptr<std::int64_t> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidInt64NullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::shared_ptr<std::int64_t> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( UInt64NullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::shared_ptr<std::uint64_t> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( UInt64NullableUnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::shared_ptr<std::uint64_t> > in;
	in.emplace("value1", std::shared_ptr<std::uint64_t>(new std::uint64_t(4711471147114711)));
	in.emplace("value2", std::shared_ptr<std::uint64_t>(new std::uint64_t(4712471247124712)));
	in.emplace("value3", std::shared_ptr<std::uint64_t>(nullptr));
	JXXON::UnorderedMap< std::shared_ptr<std::uint64_t> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidUInt64NullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::shared_ptr<std::uint64_t> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( IntMaxNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":-4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::shared_ptr<std::intmax_t> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( IntMaxNullableUnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::shared_ptr<std::intmax_t> > in;
	in.emplace("value1", std::shared_ptr<std::intmax_t>(new std::intmax_t(-4711471147114711)));
	in.emplace("value2", std::shared_ptr<std::intmax_t>(new std::intmax_t(4711471147114711)));
	in.emplace("value3", std::shared_ptr<std::intmax_t>(nullptr));
	JXXON::UnorderedMap< std::shared_ptr<std::intmax_t> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidIntMaxNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::shared_ptr<std::intmax_t> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( UIntMaxNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::shared_ptr<std::uintmax_t> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( UIntMaxNullableUnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::shared_ptr<std::uintmax_t> > in;
	in.emplace("value1", std::shared_ptr<std::uintmax_t>(new std::uintmax_t(4711471147114711)));
	in.emplace("value2", std::shared_ptr<std::uintmax_t>(new std::uintmax_t(4712471247124712)));
	in.emplace("value3", std::shared_ptr<std::uintmax_t>(nullptr));
	JXXON::UnorderedMap< std::shared_ptr<std::uintmax_t> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidUIntMaxNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::shared_ptr<std::uintmax_t> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( FloatNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":3.25}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::shared_ptr<float> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( FloatNullableUnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::shared_ptr<float> > in;
	in.emplace("value1", std::shared_ptr<float>(new float(3.25)));
	in.emplace("value2", std::shared_ptr<float>(new float(3.75)));
	in.emplace("value3", std::shared_ptr<float>(nullptr));
	JXXON::UnorderedMap< std::shared_ptr<float> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidFloatNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::shared_ptr<float> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( DoubleNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":3.25}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::shared_ptr<double> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( DoubleNullableUnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::shared_ptr<double> > in;
	in.emplace("value1", std::shared_ptr<double>(new double(3.25)));
	in.emplace("value2", std::shared_ptr<double>(new double(3.75)));
	in.emplace("value3", std::shared_ptr<double>(nullptr));
	JXXON::UnorderedMap< std::shared_ptr<double> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidDoubleNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::shared_ptr<double> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( BoolNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":false}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::shared_ptr<bool> > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( BoolNullableUnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::shared_ptr<bool> > in;
	in.emplace("value1", std::shared_ptr<bool>(new bool(true)));
	in.emplace("value2", std::shared_ptr<bool>(new bool(false)));
	in.emplace("value3", std::shared_ptr<bool>(nullptr));
	JXXON::UnorderedMap< std::shared_ptr<bool> > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out["value1"], *in["value1"] );
	BOOST_CHECK_EQUAL( *out["value2"], *in["value2"] );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidBoolNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::shared_ptr<bool> > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NestedNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"outer\":{\"value\":\"dummy\"}}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::shared_ptr< JXXON::UnorderedMap< std::shared_ptr<std::string> > > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyNestedNullableUnorderedMap )
{
	static const std::string JSON_IN("{}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::shared_ptr< JXXON::UnorderedMap< std::shared_ptr<std::string> > > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NestedNullableUnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::shared_ptr< JXXON::UnorderedMap< std::shared_ptr<std::string> > > > in;
	in.emplace("value1", std::shared_ptr< JXXON::UnorderedMap< std::shared_ptr<std::string> > >(new JXXON::UnorderedMap< std::shared_ptr<std::string> >()));
	in["value1"]->emplace("inner1", std::shared_ptr<std::string>(new std::string("dummy1")));
	in.emplace("value2", std::shared_ptr< JXXON::UnorderedMap< std::shared_ptr<std::string> > >(new JXXON::UnorderedMap< std::shared_ptr<std::string> >()));
	in["value2"]->emplace("inner2", std::shared_ptr<std::string>(new std::string("dummy2")));
	in.emplace("value3", std::shared_ptr< JXXON::UnorderedMap< std::shared_ptr<std::string> > >(nullptr));
	JXXON::UnorderedMap< std::shared_ptr< JXXON::UnorderedMap< std::shared_ptr<std::string> > > > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out.at("value1")->at("inner1"), *in.at("value1")->at("inner1") );
	BOOST_CHECK_EQUAL( *out.at("value2")->at("inner2"), *in.at("value2")->at("inner2") );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidNestedNullableUnorderedMapString )
{
	static const std::string JSON_IN("{\"outer\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::shared_ptr< JXXON::UnorderedMap< std::shared_ptr<std::string> > > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( InvalidNestedNullableUnorderedMapArray )
{
	static const std::string JSON_IN("{\"outer\":[\"invalid\"]}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::shared_ptr< JXXON::UnorderedMap< std::shared_ptr<std::string> > > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ArrayAsNestedNullableUnorderedMap )
{
	static const std::string JSON_IN("[{\"outer\":{\"value\":\"dummy\"}}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::shared_ptr< JXXON::UnorderedMap< std::shared_ptr<std::string> > > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ListNullableUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":[\"dummy\"]}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::shared_ptr< JXXON::List< std::shared_ptr<std::string> > > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyListNullableUnorderedMap )
{
	static const std::string JSON_IN("{}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::shared_ptr< JXXON::List< std::shared_ptr<std::string> > > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( ListNullableUnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::shared_ptr< JXXON::List< std::shared_ptr<std::string> > > > in;
	in.emplace("value1", std::shared_ptr< JXXON::List< std::shared_ptr<std::string> > >(new JXXON::List< std::shared_ptr<std::string> >()));
	in["value1"]->emplace_back(std::shared_ptr<std::string>(new std::string("dummy1")));
	in.emplace("value2", std::shared_ptr< JXXON::List< std::shared_ptr<std::string> > >(new JXXON::List< std::shared_ptr<std::string> >()));
	in["value2"]->emplace_back(std::shared_ptr<std::string>(new std::string("dummy2")));
	in.emplace("value3", std::shared_ptr< JXXON::List< std::shared_ptr<std::string> > >(nullptr));
	JXXON::UnorderedMap< std::shared_ptr< JXXON::List< std::shared_ptr<std::string> > > > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( *out.at("value1")->front(), *in.at("value1")->front() );
	BOOST_CHECK_EQUAL( *out.at("value2")->front(), *in.at("value2")->front() );
	BOOST_CHECK( !out["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidListNullableUnorderedMapString )
{
	static const std::string JSON_IN("{\"outer\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::shared_ptr< JXXON::List< std::shared_ptr<std::string> > > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( InvalidListNullableUnorderedMapObject )
{
	static const std::string JSON_IN("{\"outer\":{\"inner\":\"invalid\"}}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::shared_ptr< JXXON::List< std::shared_ptr<std::string> > > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NullValue )
{
	static const std::string JSON_IN("null");

	BOOST_CHECK_THROW(JXXON::Json json(JSON_IN), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( InvalidValue )
{
	static const std::string JSON_IN("acafkna");

	BOOST_CHECK_THROW(JXXON::Json json(JSON_IN), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ReadObjectFromStream )
{
	static const std::string JSON_IN("{\"value\":\"dummy\"}");
	std::istringstream in(JSON_IN);
	JXXON::Json json;
	in >> json;
	Model::NullableStringObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( WriteObjectToStream )
{
	static const std::string JSON_IN("{\"value\":\"dummy\"}");
	JXXON::Json json(JSON_IN);
	Model::NullableStringObject object( json );
	std::ostringstream out;
	out << object.toJson();

	BOOST_CHECK_EQUAL( out.str(), JSON_IN );
}

