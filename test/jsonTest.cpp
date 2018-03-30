//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE JXXON
#include <boost/test/unit_test.hpp>

#include "Model/StringObject.h"
#include "Model/IntObject.h"
#include "Model/UIntObject.h"
#include "Model/Int64Object.h"
#include "Model/UInt64Object.h"
#include "Model/IntMaxObject.h"
#include "Model/UIntMaxObject.h"
#include "Model/FloatObject.h"
#include "Model/DoubleObject.h"
#include "Model/BoolObject.h"
#include "Model/NestedObject.h"
#include "Model/VectorOfStringObject.h"
#include "Model/ListOfStringObject.h"
#include "JXXON/Error.h"
#include "JXXON/Vector.h"
#include "JXXON/List.h"
#include "JXXON/Map.h"
#include "JXXON/UnorderedMap.h"

BOOST_AUTO_TEST_CASE( StringObject )
{
	static const std::string JSON_IN("{\"value\":\"dummy\"}");
	JXXON::Json json(JSON_IN);
	Model::StringObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyStringObject )
{
	static const std::string JSON_IN("{}");
	static const std::string JSON_OUT("{\"value\":\"\"}");
	JXXON::Json json(JSON_IN);
	Model::StringObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( InvalidStringObject )
{
	static const std::string JSON_IN("{\"value\":{\"inner\":\"dummy\"}}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::StringObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( IntObject )
{
	static const std::string JSON_IN("{\"value\":-4711}");
	JXXON::Json json(JSON_IN);
	Model::IntObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidIntObject )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::IntObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( UIntObject )
{
	static const std::string JSON_IN("{\"value\":4711}");
	JXXON::Json json(JSON_IN);
	Model::UIntObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidUIntObject )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::UIntObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( Int64Object )
{
	static const std::string JSON_IN("{\"value\":-4711471147114711}");
	JXXON::Json json(JSON_IN);
	Model::Int64Object object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidInt64Object )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::Int64Object object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( UInt64Object )
{
	static const std::string JSON_IN("{\"value\":4711471147114711}");
	JXXON::Json json(JSON_IN);
	Model::UInt64Object object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidUInt64Object )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::UInt64Object object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( IntMaxObject )
{
	static const std::string JSON_IN("{\"value\":-4711471147114711}");
	JXXON::Json json(JSON_IN);
	Model::IntMaxObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidIntMaxObject )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::IntMaxObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( UIntMaxObject )
{
	static const std::string JSON_IN("{\"value\":4711471147114711}");
	JXXON::Json json(JSON_IN);
	Model::UIntMaxObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidUIntMaxObject )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::UIntMaxObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( FloatObject )
{
	static const std::string JSON_IN("{\"value\":3.25}");
	JXXON::Json json(JSON_IN);
	Model::FloatObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidFloatObject )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::FloatObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( DoubleObject )
{
	static const std::string JSON_IN("{\"value\":3.25}");
	JXXON::Json json(JSON_IN);
	Model::DoubleObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidDoubleObject )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::DoubleObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( BoolObject )
{
	static const std::string JSON_IN("{\"value\":false}");
	JXXON::Json json(JSON_IN);
	Model::BoolObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidBoolObject )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::BoolObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NestedObject )
{
	static const std::string JSON_IN("{\"outer\":{\"value\":\"dummy\"}}");
	JXXON::Json json(JSON_IN);
	Model::NestedObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyNestedObject )
{
	static const std::string JSON_IN("{}");
	static const std::string JSON_OUT("{\"outer\":{\"value\":\"\"}}");
	JXXON::Json json(JSON_IN);
	Model::NestedObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( InvalidNestedObject )
{
	static const std::string JSON_IN("{\"outer\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::NestedObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ArrayAsNestedObject )
{
	static const std::string JSON_IN("[{\"outer\":{\"value\":\"dummy\"}}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(Model::NestedObject object( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( VectorOfObject )
{
	static const std::string JSON_IN("[{\"value\":\"dummy1\"},{\"value\":\"dummy2\"}]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< Model::StringObject > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyVectorOfObject )
{
	static const std::string JSON_IN("[]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< Model::StringObject > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( VectorOfInvalidObject )
{
	static const std::string JSON_IN("[\"invalid\"]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< Model::StringObject > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ObjectAsVectorOfObject )
{
	static const std::string JSON_IN("{\"value\":[{\"value\":\"dummy1\"},{\"value\":\"dummy2\"}]}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< Model::StringObject > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( VectorOfObjectWithNull )
{
	static const std::string JSON_IN("[{\"value\":\"dummy1\"},{\"value\":\"dummy2\"},null]");
	static const std::string JSON_OUT("[{\"value\":\"dummy1\"},{\"value\":\"dummy2\"},{\"value\":\"\"}]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< Model::StringObject > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( VectorOfString )
{
	static const std::string JSON_IN("[\"dummy1\",\"dummy2\"]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::string > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyVectorOfString )
{
	static const std::string JSON_IN("[]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::string > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( VectorOfInvalidString )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::string > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ObjectAsVectorOfString )
{
	static const std::string JSON_IN("{\"value\":[\"dummy1\",\"dummy2\"]}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::string > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( VectorOfStringWithNull )
{
	static const std::string JSON_IN("[\"dummy1\",\"dummy2\",null]");
	static const std::string JSON_OUT("[\"dummy1\",\"dummy2\",\"\"]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::string > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( VectorOfInt )
{
	static const std::string JSON_IN("[-4711,-4712]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< int > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( VectorOfInvalidInt )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< int > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( VectorOfIntWithNull )
{
	static const std::string JSON_IN("[-4711,-4712,null]");
	static const std::string JSON_OUT("[-4711,-4712,0]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< int > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( VectorOfUInt )
{
	static const std::string JSON_IN("[4711,4712]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< unsigned int > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( VectorOfInvalidUInt )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< unsigned int > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( VectorOfUIntWithNull )
{
	static const std::string JSON_IN("[4711,4712,null]");
	static const std::string JSON_OUT("[4711,4712,0]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< unsigned int > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( VectorOfInt64 )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::int64_t > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( VectorOfInvalidInt64 )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::int64_t > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( VectorOfInt64WithNull )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712,null]");
	static const std::string JSON_OUT("[-4711471147114711,-4712471247124712,0]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::int64_t > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( VectorOfUInt64 )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::uint64_t > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( VectorOfInvalidUInt64 )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::uint64_t > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( VectorOfUInt64WithNull )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712,null]");
	static const std::string JSON_OUT("[4711471147114711,4712471247124712,0]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::uint64_t > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( VectorOfIntMax )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::intmax_t > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( VectorOfInvalidIntMax )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::intmax_t > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( VectorOfIntMaxWithNull )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712,null]");
	static const std::string JSON_OUT("[-4711471147114711,-4712471247124712,0]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::intmax_t > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( VectorOfUIntMax )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::uintmax_t > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( VectorOfInvalidUIntMax )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< std::uintmax_t > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( VectorOfUIntMaxWithNull )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712,null]");
	static const std::string JSON_OUT("[4711471147114711,4712471247124712,0]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< std::uintmax_t > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( VectorOfFloat )
{
	static const std::string JSON_IN("[3.25,6.75]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< float > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( VectorOfInvalidFloat )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< float > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( VectorOfFloatWithNull )
{
	static const std::string JSON_IN("[3.25,6.75,null]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< float > vector( json );
	std::string out(vector.toJson().toString());

	BOOST_CHECK( out == "[3.25,6.75,0.0]" || out == "[3.25,6.75,0]" );
}

BOOST_AUTO_TEST_CASE( VectorOfDouble )
{
	static const std::string JSON_IN("[3.25,6.75]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< double > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( VectorOfInvalidDouble )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< double > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( VectorOfDoubleWithNull )
{
	static const std::string JSON_IN("[3.25,6.75,null]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< double > vector( json );
	std::string out(vector.toJson().toString());

	BOOST_CHECK( out == "[3.25,6.75,0.0]" || out == "[3.25,6.75,0]" );
}

BOOST_AUTO_TEST_CASE( VectorOfBool )
{
	static const std::string JSON_IN("[true,false]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< bool > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( VectorOfInvalidBool )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< bool > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( VectorOfBoolWithNull )
{
	static const std::string JSON_IN("[true,false,null]");
	static const std::string JSON_OUT("[true,false,false]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< bool > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( NestedVectorOfString )
{
	static const std::string JSON_IN("[[\"dummy1\",\"dummy2\"],[\"dummy3\",\"dummy4\"]]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< JXXON::Vector< std::string > > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidNestedVectorOfString )
{
	static const std::string JSON_IN("[\"invalid\"]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Vector< JXXON::Vector< std::string > > vector( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NestedVectorOfStringWithNull )
{
	static const std::string JSON_IN("[[\"dummy1\",\"dummy2\"],[\"dummy3\",\"dummy4\"],null]");
	static const std::string JSON_OUT("[[\"dummy1\",\"dummy2\"],[\"dummy3\",\"dummy4\"],[]]");
	JXXON::Json json(JSON_IN);
	JXXON::Vector< JXXON::Vector< std::string > > vector( json );

	BOOST_CHECK_EQUAL( vector.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( VectorOfStringObject )
{
	static const std::string JSON_IN("{\"value\":[\"dummy1\",\"dummy2\"]}");
	JXXON::Json json(JSON_IN);
	Model::VectorOfStringObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( ListOfObject )
{
	static const std::string JSON_IN("[{\"value\":\"dummy1\"},{\"value\":\"dummy2\"}]");
	JXXON::Json json(JSON_IN);
	JXXON::List< Model::StringObject > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyListOfObject )
{
	static const std::string JSON_IN("[]");
	JXXON::Json json(JSON_IN);
	JXXON::List< Model::StringObject > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( ListOfInvalidObject )
{
	static const std::string JSON_IN("[\"invalid\"]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< Model::StringObject > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ObjectAsListOfObject )
{
	static const std::string JSON_IN("{\"value\":[{\"value\":\"dummy1\"},{\"value\":\"dummy2\"}]}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< Model::StringObject > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ListOfObjectWithNull )
{
	static const std::string JSON_IN("[{\"value\":\"dummy1\"},{\"value\":\"dummy2\"},null]");
	static const std::string JSON_OUT("[{\"value\":\"dummy1\"},{\"value\":\"dummy2\"},{\"value\":\"\"}]");
	JXXON::Json json(JSON_IN);
	JXXON::List< Model::StringObject > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( ListOfString )
{
	static const std::string JSON_IN("[\"dummy1\",\"dummy2\"]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::string > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyListOfString )
{
	static const std::string JSON_IN("[]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::string > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( ListOfInvalidString )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::string > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ObjectAsListOfString )
{
	static const std::string JSON_IN("{\"value\":[\"dummy1\",\"dummy2\"]}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::string > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ListOfStringWithNull )
{
	static const std::string JSON_IN("[\"dummy1\",\"dummy2\",null]");
	static const std::string JSON_OUT("[\"dummy1\",\"dummy2\",\"\"]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::string > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( ListOfInt )
{
	static const std::string JSON_IN("[-4711,-4712]");
	JXXON::Json json(JSON_IN);
	JXXON::List< int > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( ListOfInvalidInt )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< int > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ListOfIntWithNull )
{
	static const std::string JSON_IN("[-4711,-4712,null]");
	static const std::string JSON_OUT("[-4711,-4712,0]");
	JXXON::Json json(JSON_IN);
	JXXON::List< int > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( ListOfUInt )
{
	static const std::string JSON_IN("[4711,4712]");
	JXXON::Json json(JSON_IN);
	JXXON::List< unsigned int > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( ListOfInvalidUInt )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< unsigned int > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ListOfUIntWithNull )
{
	static const std::string JSON_IN("[4711,4712,null]");
	static const std::string JSON_OUT("[4711,4712,0]");
	JXXON::Json json(JSON_IN);
	JXXON::List< unsigned int > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( ListOfInt64 )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::int64_t > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( ListOfInvalidInt64 )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::int64_t > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ListOfInt64WithNull )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712,null]");
	static const std::string JSON_OUT("[-4711471147114711,-4712471247124712,0]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::int64_t > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( ListOfUInt64 )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::uint64_t > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( ListOfInvalidUInt64 )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::uint64_t > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ListOfUInt64WithNull )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712,null]");
	static const std::string JSON_OUT("[4711471147114711,4712471247124712,0]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::uint64_t > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( ListOfIntMax )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::intmax_t > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( ListOfInvalidIntMax )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::intmax_t > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ListOfIntMaxWithNull )
{
	static const std::string JSON_IN("[-4711471147114711,-4712471247124712,null]");
	static const std::string JSON_OUT("[-4711471147114711,-4712471247124712,0]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::intmax_t > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( ListOfUIntMax )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::uintmax_t > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( ListOfInvalidUIntMax )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< std::uintmax_t > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ListOfUIntMaxWithNull )
{
	static const std::string JSON_IN("[4711471147114711,4712471247124712,null]");
	static const std::string JSON_OUT("[4711471147114711,4712471247124712,0]");
	JXXON::Json json(JSON_IN);
	JXXON::List< std::uintmax_t > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( ListOfFloat )
{
	static const std::string JSON_IN("[3.25,6.75]");
	JXXON::Json json(JSON_IN);
	JXXON::List< float > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( ListOfInvalidFloat )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< float > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ListOfFloatWithNull )
{
	static const std::string JSON_IN("[3.25,6.75,null]");
	JXXON::Json json(JSON_IN);
	JXXON::List< float > list( json );
	std::string out(list.toJson().toString());

	BOOST_CHECK( out == "[3.25,6.75,0.0]" || out == "[3.25,6.75,0]" );
}

BOOST_AUTO_TEST_CASE( ListOfDouble )
{
	static const std::string JSON_IN("[3.25,6.75]");
	JXXON::Json json(JSON_IN);
	JXXON::List< double > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( ListOfInvalidDouble )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< double > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ListOfDoubleWithNull )
{
	static const std::string JSON_IN("[3.25,6.75,null]");
	JXXON::Json json(JSON_IN);
	JXXON::List< double > list( json );
	std::string out(list.toJson().toString());

	BOOST_CHECK( out == "[3.25,6.75,0.0]" || out == "[3.25,6.75,0]" );
}

BOOST_AUTO_TEST_CASE( ListOfBool )
{
	static const std::string JSON_IN("[true,false]");
	JXXON::Json json(JSON_IN);
	JXXON::List< bool > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( ListOfInvalidBool )
{
	static const std::string JSON_IN("[{\"value\":\"invalid\"},{\"value\":\"invalid\"}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< bool > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ListOfBoolWithNull )
{
	static const std::string JSON_IN("[true,false,null]");
	static const std::string JSON_OUT("[true,false,false]");
	JXXON::Json json(JSON_IN);
	JXXON::List< bool > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( NestedListOfString )
{
	static const std::string JSON_IN("[[\"dummy1\",\"dummy2\"],[\"dummy3\",\"dummy4\"]]");
	JXXON::Json json(JSON_IN);
	JXXON::List< JXXON::List< std::string > > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( InvalidNestedListOfString )
{
	static const std::string JSON_IN("[\"invalid\"]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::List< JXXON::List< std::string > > list( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NestedListOfStringWithNull )
{
	static const std::string JSON_IN("[[\"dummy1\",\"dummy2\"],[\"dummy3\",\"dummy4\"],null]");
	static const std::string JSON_OUT("[[\"dummy1\",\"dummy2\"],[\"dummy3\",\"dummy4\"],[]]");
	JXXON::Json json(JSON_IN);
	JXXON::List< JXXON::List< std::string > > list( json );

	BOOST_CHECK_EQUAL( list.toJson().toString(), JSON_OUT );
}

BOOST_AUTO_TEST_CASE( ListOfStringObject )
{
	static const std::string JSON_IN("{\"value\":[\"dummy1\",\"dummy2\"]}");
	JXXON::Json json(JSON_IN);
	Model::ListOfStringObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( StringMap )
{
	static const std::string JSON_IN("{\"value\":\"dummy\"}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::string > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyStringMap )
{
	static const std::string JSON_IN("{}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::string > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( StringMapWithNull )
{
	JXXON::Map< std::string > in;
	in.emplace("value1", "dummy1");
	in.emplace("value2", "dummy2");
	in.emplace("value3", "");
	JXXON::Map< std::string > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidStringMap )
{
	static const std::string JSON_IN("{\"value\":{\"inner\":\"dummy\"}}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::string > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( IntMap )
{
	static const std::string JSON_IN("{\"value\":-4711}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< int > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( IntMapWithNull )
{
	JXXON::Map< int > in;
	in.emplace("value1", -4711);
	in.emplace("value2", 4711);
	in.emplace("value3", 0);
	JXXON::Map< int > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidIntMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< int > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( UIntMap )
{
	static const std::string JSON_IN("{\"value\":4711}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< unsigned int > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( UIntMapWithNull )
{
	JXXON::Map< unsigned int > in;
	in.emplace("value1", 4711);
	in.emplace("value2", 4712);
	in.emplace("value3", 0);
	JXXON::Map< unsigned int > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidUIntMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< unsigned int > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( Int64Map )
{
	static const std::string JSON_IN("{\"value\":-4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::int64_t > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( Int64MapWithNull )
{
	JXXON::Map< std::int64_t > in;
	in.emplace("value1", -4711471147114711);
	in.emplace("value2", 4711471147114711);
	in.emplace("value3", 0);
	JXXON::Map< std::int64_t > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidInt64Map )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::int64_t > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( UInt64Map )
{
	static const std::string JSON_IN("{\"value\":4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::uint64_t > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( UInt64MapWithNull )
{
	JXXON::Map< std::uint64_t > in;
	in.emplace("value1", 4711471147114711);
	in.emplace("value2", 4712471247124712);
	in.emplace("value3", 0);
	JXXON::Map< std::uint64_t > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidUInt64Map )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::uint64_t > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( IntMaxMap )
{
	static const std::string JSON_IN("{\"value\":-4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::intmax_t > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( IntMaxMapWithNull )
{
	JXXON::Map< std::intmax_t > in;
	in.emplace("value1", -4711471147114711);
	in.emplace("value2", 4711471147114711);
	in.emplace("value3", 0);
	JXXON::Map< std::intmax_t > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidIntMaxMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::intmax_t > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( UIntMaxMap )
{
	static const std::string JSON_IN("{\"value\":4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< std::uintmax_t > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( UIntMaxMapWithNull )
{
	JXXON::Map< std::uintmax_t > in;
	in.emplace("value1", 4711471147114711);
	in.emplace("value2", 4712471247124712);
	in.emplace("value3", 0);
	JXXON::Map< std::uintmax_t > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidUIntMaxMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< std::uintmax_t > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( FloatMap )
{
	static const std::string JSON_IN("{\"value\":3.25}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< float > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( FloatMapWithNull )
{
	JXXON::Map< float > in;
	in.emplace("value1", 3.25F);
	in.emplace("value2", 3.75F);
	in.emplace("value3", 0.0F);
	JXXON::Map< float > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidFloatMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< float > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( DoubleMap )
{
	static const std::string JSON_IN("{\"value\":3.25}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< double > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( DoubleMapWithNull )
{
	JXXON::Map< double > in;
	in.emplace("value1", 3.25);
	in.emplace("value2", 3.75);
	in.emplace("value3", 0.0);
	JXXON::Map< double > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidDoubleMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< double > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( BoolMap )
{
	static const std::string JSON_IN("{\"value\":false}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< bool > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( BoolMapTrueFalse )
{
	JXXON::Map< bool > in;
	in.emplace("value1", true);
	in.emplace("value2", false);
	JXXON::Map< bool > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
}

BOOST_AUTO_TEST_CASE( InvalidBoolMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< bool > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NestedMap )
{
	static const std::string JSON_IN("{\"outer\":{\"value\":\"dummy\"}}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< JXXON::Map< std::string > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyNestedMap )
{
	static const std::string JSON_IN("{}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< JXXON::Map< std::string > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NestedMapWithNull )
{
	JXXON::Map< JXXON::Map<std::string > > in;
	in.emplace("value1", JXXON::Map< std::string >(JXXON::Map<std::string >()));
	in["value1"].emplace("inner1", std::string("dummy1"));
	in.emplace("value2", JXXON::Map< std::string >(JXXON::Map<std::string >()));
	in["value2"].emplace("inner2", std::string("dummy2"));
	in.emplace("value3", JXXON::Map< std::string >(JXXON::Map<std::string >()));
	JXXON::Map< JXXON::Map<std::string > > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out.at("value1").at("inner1"), in.at("value1").at("inner1") );
	BOOST_CHECK_EQUAL( out.at("value2").at("inner2"), in.at("value2").at("inner2") );
	BOOST_CHECK_EQUAL( out.at("value3").size(), in.at("value3").size() );
}

BOOST_AUTO_TEST_CASE( InvalidNestedMapString )
{
	static const std::string JSON_IN("{\"outer\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< JXXON::Map< std::string > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( InvalidNestedMapArray )
{
	static const std::string JSON_IN("{\"outer\":[\"invalid\"]}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< JXXON::Map< std::string > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ArrayAsNestedMap )
{
	static const std::string JSON_IN("[{\"outer\":{\"value\":\"dummy\"}}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< JXXON::Map< std::string > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( VectorMap )
{
	static const std::string JSON_IN("{\"value\":[\"dummy\"]}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< JXXON::Vector< std::string > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyVectorMap )
{
	static const std::string JSON_IN("{}");
	JXXON::Json json(JSON_IN);
	JXXON::Map< JXXON::Vector< std::string > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( VectorMapWithNull )
{
	JXXON::Map< JXXON::Vector< std::string > > in;
	in.emplace("value1", JXXON::Vector< std::string >(JXXON::Vector< std::string >()));
	in["value1"].emplace_back(std::string("dummy1"));
	in.emplace("value2", JXXON::Vector< std::string >(JXXON::Vector< std::string >()));
	in["value2"].emplace_back(std::string("dummy2"));
	in.emplace("value3", JXXON::Vector< std::string >(JXXON::Vector< std::string >()));
	JXXON::Map< JXXON::Vector< std::string > > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out.at("value1").at(0), in.at("value1").at(0) );
	BOOST_CHECK_EQUAL( out.at("value2").at(0), in.at("value2").at(0) );
	BOOST_CHECK_EQUAL( out.at("value3").size(), in.at("value3").size() );
}

BOOST_AUTO_TEST_CASE( InvalidVectorMapString )
{
	static const std::string JSON_IN("{\"outer\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< JXXON::Vector< std::string > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( InvalidVectorMapObject )
{
	static const std::string JSON_IN("{\"outer\":{\"inner\":\"invalid\"}}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::Map< JXXON::Vector< std::string > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( StringUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"dummy\"}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::string > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyStringUnorderedMap )
{
	static const std::string JSON_IN("{}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::string > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( StringUnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::string > in;
	in.emplace("value1", "dummy1");
	in.emplace("value2", "dummy2");
	in.emplace("value3", "");
	JXXON::UnorderedMap< std::string > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidStringUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":{\"inner\":\"dummy\"}}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::string > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( IntUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":-4711}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< int > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( IntUnorderedMapWithNull )
{
	JXXON::UnorderedMap< int > in;
	in.emplace("value1", -4711);
	in.emplace("value2", 4711);
	in.emplace("value3", 0);
	JXXON::UnorderedMap< int > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidIntUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< int > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( UIntUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":4711}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< unsigned int > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( UIntUnorderedMapWithNull )
{
	JXXON::UnorderedMap< unsigned int > in;
	in.emplace("value1", 4711);
	in.emplace("value2", 4712);
	in.emplace("value3", 0);
	JXXON::UnorderedMap< unsigned int > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidUIntUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< unsigned int > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( Int64UnorderedMap )
{
	static const std::string JSON_IN("{\"value\":-4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::int64_t > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( Int64UnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::int64_t > in;
	in.emplace("value1", -4711471147114711);
	in.emplace("value2", 4711471147114711);
	in.emplace("value3", 0);
	JXXON::UnorderedMap< std::int64_t > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidInt64UnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::int64_t > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( UInt64UnorderedMap )
{
	static const std::string JSON_IN("{\"value\":4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::uint64_t > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( UInt64UnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::uint64_t > in;
	in.emplace("value1", 4711471147114711);
	in.emplace("value2", 4712471247124712);
	in.emplace("value3", 0);
	JXXON::UnorderedMap< std::uint64_t > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidUInt64UnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::uint64_t > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( IntMaxUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":-4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::intmax_t > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( IntMaxUnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::intmax_t > in;
	in.emplace("value1", -4711471147114711);
	in.emplace("value2", 4711471147114711);
	in.emplace("value3", 0);
	JXXON::UnorderedMap< std::intmax_t > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidIntMaxUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::intmax_t > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( UIntMaxUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":4711471147114711}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< std::uintmax_t > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( UIntMaxUnorderedMapWithNull )
{
	JXXON::UnorderedMap< std::uintmax_t > in;
	in.emplace("value1", 4711471147114711);
	in.emplace("value2", 4712471247124712);
	in.emplace("value3", 0);
	JXXON::UnorderedMap< std::uintmax_t > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidUIntMaxUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< std::uintmax_t > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( FloatUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":3.25}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< float > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( FloatUnorderedMapWithNull )
{
	JXXON::UnorderedMap< float > in;
	in.emplace("value1", 3.25F);
	in.emplace("value2", 3.75F);
	in.emplace("value3", 0.0F);
	JXXON::UnorderedMap< float > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidFloatUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< float > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( DoubleUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":3.25}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< double > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( DoubleUnorderedMapWithNull )
{
	JXXON::UnorderedMap< double > in;
	in.emplace("value1", 3.25);
	in.emplace("value2", 3.75);
	in.emplace("value3", 0.0);
	JXXON::UnorderedMap< double > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
	BOOST_CHECK_EQUAL( out["value3"], in["value3"] );
}

BOOST_AUTO_TEST_CASE( InvalidDoubleUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< double > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( BoolUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":false}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< bool > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( BoolUnorderedMapTrueFalse )
{
	JXXON::UnorderedMap< bool > in;
	in.emplace("value1", true);
	in.emplace("value2", false);
	JXXON::UnorderedMap< bool > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out["value1"], in["value1"] );
	BOOST_CHECK_EQUAL( out["value2"], in["value2"] );
}

BOOST_AUTO_TEST_CASE( InvalidBoolUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< bool > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( NestedUnorderedMap )
{
	static const std::string JSON_IN("{\"outer\":{\"value\":\"dummy\"}}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< JXXON::UnorderedMap< std::string > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyNestedUnorderedMap )
{
	static const std::string JSON_IN("{}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< JXXON::UnorderedMap< std::string > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( NestedUnorderedMapWithNull )
{
	JXXON::UnorderedMap< JXXON::UnorderedMap< std::string > > in;
	in.emplace("value1", JXXON::UnorderedMap< std::string >(JXXON::UnorderedMap< std::string >()));
	in["value1"].emplace("inner1", std::string("dummy1"));
	in.emplace("value2", JXXON::UnorderedMap< std::string >(JXXON::UnorderedMap< std::string >()));
	in["value2"].emplace("inner2", std::string("dummy2"));
	in.emplace("value3", JXXON::UnorderedMap< std::string >(JXXON::UnorderedMap< std::string >()));
	JXXON::UnorderedMap< JXXON::UnorderedMap< std::string > > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out.at("value1").at("inner1"), in.at("value1").at("inner1") );
	BOOST_CHECK_EQUAL( out.at("value2").at("inner2"), in.at("value2").at("inner2") );
	BOOST_CHECK_EQUAL( out.at("value3").size(), in.at("value3").size() );
}

BOOST_AUTO_TEST_CASE( InvalidNestedUnorderedMapString )
{
	static const std::string JSON_IN("{\"outer\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< JXXON::UnorderedMap< std::string > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( InvalidNestedUnorderedMapArray )
{
	static const std::string JSON_IN("{\"outer\":[\"invalid\"]}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< JXXON::UnorderedMap< std::string > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ArrayAsNestedUnorderedMap )
{
	static const std::string JSON_IN("[{\"outer\":{\"value\":\"dummy\"}}]");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< JXXON::UnorderedMap< std::string > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( ListUnorderedMap )
{
	static const std::string JSON_IN("{\"value\":[\"dummy\"]}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< JXXON::List< std::string > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( EmptyListUnorderedMap )
{
	static const std::string JSON_IN("{}");
	JXXON::Json json(JSON_IN);
	JXXON::UnorderedMap< JXXON::List< std::string > > map( json );

	BOOST_CHECK_EQUAL( map.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( ListUnorderedMapWithNull )
{
	JXXON::UnorderedMap< JXXON::List< std::string > > in;
	in.emplace("value1", JXXON::List< std::string >(JXXON::List< std::string >()));
	in["value1"].emplace_back(std::string("dummy1"));
	in.emplace("value2", JXXON::List< std::string >(JXXON::List< std::string >()));
	in["value2"].emplace_back(std::string("dummy2"));
	in.emplace("value3", JXXON::List< std::string >(JXXON::List< std::string >()));
	JXXON::UnorderedMap< JXXON::List< std::string > > out( in.toJson() );

	BOOST_CHECK_EQUAL( out.size(), in.size() );
	BOOST_CHECK_EQUAL( out.at("value1").front(), in.at("value1").front() );
	BOOST_CHECK_EQUAL( out.at("value2").front(), in.at("value2").front() );
	BOOST_CHECK_EQUAL( out.at("value3").size(), in.at("value3").size() );
}

BOOST_AUTO_TEST_CASE( InvalidListUnorderedMapString )
{
	static const std::string JSON_IN("{\"outer\":\"invalid\"}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< JXXON::List< std::string > > map( json ), JXXON::Error);
}

BOOST_AUTO_TEST_CASE( InvalidListUnorderedMapObject )
{
	static const std::string JSON_IN("{\"outer\":{\"inner\":\"invalid\"}}");
	JXXON::Json json(JSON_IN);

	BOOST_CHECK_THROW(JXXON::UnorderedMap< JXXON::List< std::string > > map( json ), JXXON::Error);
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
	Model::StringObject object( json );

	BOOST_CHECK_EQUAL( object.toJson().toString(), JSON_IN );
}

BOOST_AUTO_TEST_CASE( WriteObjectToStream )
{
	static const std::string JSON_IN("{\"value\":\"dummy\"}");
	JXXON::Json json(JSON_IN);
	Model::StringObject object( json );
	std::ostringstream out;
	out << object.toJson();

	BOOST_CHECK_EQUAL( out.str(), JSON_IN );
}

