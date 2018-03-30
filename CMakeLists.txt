#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:     BSL-1.0
#

cmake_minimum_required(VERSION 3.0)
project(JXXON VERSION 0.1.0 LANGUAGES CXX)
include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS NO)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

if(JXXON_IMPL STREQUAL "poco")
	if(NOT Poco_INCLUDE_DIRS OR NOT Poco_LIBRARIES)
		find_package(Poco COMPONENTS JSON REQUIRED)
	endif()
	set(jxxon_impl_INCLUDE_DIRS ${Poco_INCLUDE_DIRS})
	set(jxxon_impl_LIBRARIES ${Poco_LIBRARIES})
elseif(JXXON_IMPL STREQUAL "jsoncpp")
	if(NOT JSONCPP_INCLUDE_DIRS OR NOT JSONCPP_LIBRARY)
		find_package(JsonCpp REQUIRED)
	endif()
	set(jxxon_impl_INCLUDE_DIRS ${Poco_INCLUDE_DIRS})
	set(jxxon_impl_LIBRARIES ${Poco_LIBRARIES})
else()
	message(FATAL_ERROR "JXXON_IMPL invalid or not specified. Must be \"poco\" or \"jsoncpp\".")
endif()

find_package(Polymorphic REQUIRED)

include(CheckTypeSize)
check_type_size("int" SIZEOF_INT LANGUAGE CXX)
add_definitions(-D_SIZEOF_INT=${SIZEOF_INT})
check_type_size("unsigned int" SIZEOF_UNSIGNED_INT LANGUAGE CXX)
add_definitions(-D_SIZEOF_UNSIGNED_INT=${SIZEOF_UNSIGNED_INT})
check_type_size("int64_t" SIZEOF_INT64_T LANGUAGE CXX)
add_definitions(-D_SIZEOF_INT64_T=${SIZEOF_INT64_T})
check_type_size("uint64_t" SIZEOF_UINT64_T LANGUAGE CXX)
add_definitions(-D_SIZEOF_UINT64_T=${SIZEOF_UINT64_T})
check_type_size("intmax_t" SIZEOF_INTMAX_T LANGUAGE CXX)
add_definitions(-D_SIZEOF_INTMAX_T=${SIZEOF_INTMAX_T})
check_type_size("uintmax_t" SIZEOF_UINTMAX_T LANGUAGE CXX)
add_definitions(-D_SIZEOF_UINTMAX_T=${SIZEOF_UINTMAX_T})

file(GLOB JXXON_SRCS_G src/JXXON/*.cpp src/${JXXON_IMPL}_impl/JXXON/*.cpp src/${JXXON_IMPL}_impl/JXXON/Accessor/*.cpp)
add_library(jxxon ${JXXON_SRCS_G})

target_include_directories(jxxon PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src/${JXXON_IMPL}_impl>
	$<BUILD_INTERFACE:${jxxon_impl_INCLUDE_DIRS}>
        $<INSTALL_INTERFACE:include>)
target_link_libraries(jxxon polymorphic)

install(TARGETS jxxon EXPORT JXXONConfig
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} FILES_MATCHING PATTERN "*.h")
install(EXPORT JXXONConfig DESTINATION share/JXXON/cmake)
export(TARGETS jxxon FILE JXXONConfig.cmake)

enable_testing()

# On demand build of tests. See https://cmake.org/Wiki/CMakeEmulateMakeCheck
if(NOT "${CMAKE_GENERATOR}" MATCHES "Visual Studio")
	add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --force-new-ctest-process)
else()
	add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --force-new-ctest-process -C $(Configuration))
endif()

add_subdirectory(test EXCLUDE_FROM_ALL)

add_test(NAME ObjectTest COMMAND objectTest)
add_dependencies(check objectTest)

add_test(NAME VectorTest COMMAND vectorTest)
add_dependencies(check vectorTest)

add_test(NAME ListTest COMMAND listTest)
add_dependencies(check listTest)

add_test(NAME MapTest COMMAND mapTest)
add_dependencies(check mapTest)

add_test(NAME UnorderedMapTest COMMAND unorderedMapTest)
add_dependencies(check unorderedMapTest)

add_test(NAME MiscellaneousTest COMMAND miscellaneousTest)
add_dependencies(check miscellaneousTest)
