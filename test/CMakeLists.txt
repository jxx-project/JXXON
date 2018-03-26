#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:     BSL-1.0
#

if(NOT Boost_INCLUDE_DIRS OR NOT Boost_UNIT_TEST_FRAMEWORK_LIBRARY)
	find_package(Boost COMPONENTS unit_test_framework REQUIRED)
endif()

find_package(Threads)

file(GLOB TEST_MODEL_SRCS_G Model/*.cpp)
add_library(model ${TEST_MODEL_SRCS_G})
target_include_directories(model PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(model jxxon)

add_executable(jsonTest jsonTest.cpp)
target_include_directories(jsonTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	$<BUILD_INTERFACE:${Boost_INCLUDE_DIRS}>)
target_link_libraries(jsonTest
	jxxon
	model
	${jxxon_impl_LIBRARIES}
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	${CMAKE_THREAD_LIBS_INIT})

add_executable(jsonNullableTest jsonNullableTest.cpp)
target_include_directories(jsonNullableTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	$<BUILD_INTERFACE:${Boost_INCLUDE_DIRS}>)
target_link_libraries(jsonNullableTest
	jxxon
	model
	${jxxon_impl_LIBRARIES}
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	${CMAKE_THREAD_LIBS_INIT})
