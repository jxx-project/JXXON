#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:     BSL-1.0
#

project(JXXON CXX)
cmake_minimum_required(VERSION 3.0)

set(JXXON_MAJOR_VERSION 0)
set(JXXON_MINOR_VERSION 1)
set(JXXON_PATCH_VERSION 0)
set(JXXON_VERSION ${JXXON_MAJOR_VERSION}.${JXXON_MINOR_VERSION}.${JXXON_PATCH_VERSION})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

if(JXXON_IMPL STREQUAL "poco")
	if(NOT Poco_INCLUDE_DIRS OR NOT Poco_LIBRARIES)
		find_package(Poco COMPONENTS JSON REQUIRED)
	endif()
	include_directories(${Poco_INCLUDE_DIRS})
elseif(JXXON_IMPL STREQUAL "jsoncpp")
	if(NOT JSONCPP_INCLUDE_DIRS OR NOT JSONCPP_LIBRARY)
		find_package(JsonCpp REQUIRED)
	endif()
	include_directories(${JSONCPP_INCLUDE_DIRS})
else()
	message(FATAL_ERROR "JXXON_IMPL invalid or not specified. Must be \"poco\" or \"jsoncpp\".")
endif()
include_directories(src)

if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)
endif()

add_subdirectory (src)
add_subdirectory (test)

enable_testing ()
add_test (NAME JsonTest COMMAND jsonTest)
add_test (NAME JsonNullableTest COMMAND jsonNullableTest)
