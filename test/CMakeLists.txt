#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:     BSL-1.0
#

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${Boost_INCLUDE_DIRS})

if(JXXON_IMPL STREQUAL "poco")
	set(JXXON_EXTRA_LIBRARIES ${Poco_LIBRARIES})
elseif(JXXON_IMPL STREQUAL "jsoncpp")
	set(JXXON_EXTRA_LIBRARIES JsonCpp::JsonCpp)
endif()

file(GLOB SRCS_G Model/*.cpp)
add_library(Model ${SRCS_G})

add_executable (jsonTest jsonTest.cpp)

target_link_libraries (jsonTest
	Model
	jxxon
	${JXXON_EXTRA_LIBRARIES}
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	pthread
)

add_executable (jsonNullableTest jsonNullableTest.cpp)

target_link_libraries (jsonNullableTest
	Model
	jxxon
	${JXXON_EXTRA_LIBRARIES}
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	pthread
)

