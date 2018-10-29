#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:	BSL-1.0
#

cmake_minimum_required(VERSION 3.0)
project(JXXON VERSION 1.1.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS NO)

set(Polymorphic_FIND_VERSION 1.1.0)
find_package(Polymorphic ${Polymorphic_FIND_VERSION} REQUIRED CONFIG)

if(JXXON_IMPL STREQUAL "poco")
	set(Poco_FIND_VERSION 1.6.0)
	find_package(Poco ${Poco_FIND_VERSION} COMPONENTS JSON REQUIRED CONFIG)
	set(jxxon_impl_LIBRARIES Poco::JSON)
elseif(JXXON_IMPL STREQUAL "jsoncpp")
	find_package(PkgConfig REQUIRED)
	pkg_check_modules(JSONCPP jsoncpp)
	set(jxxon_impl_INCLUDE_DIRS ${JSONCPP_INCLUDE_DIRS})
	set(jxxon_impl_LIBRARIES ${JSONCPP_LIBRARIES})
else()
	message(FATAL_ERROR "JXXON_IMPL invalid or not specified. Must be \"poco\" or \"jsoncpp\".")
endif()

include(CheckTypeSize)
check_type_size("int8_t" SIZEOF_INT8_T LANGUAGE CXX)
add_definitions(-D_SIZEOF_INT8_T=${SIZEOF_INT8_T})
check_type_size("uint8_t" SIZEOF_UINT8_T LANGUAGE CXX)
add_definitions(-D_SIZEOF_UINT8_T=${SIZEOF_UINT8_T})
check_type_size("int16_t" SIZEOF_INT16_T LANGUAGE CXX)
add_definitions(-D_SIZEOF_INT16_T=${SIZEOF_INT16_T})
check_type_size("uint16_t" SIZEOF_UINT16_T LANGUAGE CXX)
add_definitions(-D_SIZEOF_UINT16_T=${SIZEOF_UINT16_T})
check_type_size("int32_t" SIZEOF_INT32_T LANGUAGE CXX)
add_definitions(-D_SIZEOF_INT32_T=${SIZEOF_INT32_T})
check_type_size("uint32_t" SIZEOF_UINT32_T LANGUAGE CXX)
add_definitions(-D_SIZEOF_UINT32_T=${SIZEOF_UINT32_T})
check_type_size("int64_t" SIZEOF_INT64_T LANGUAGE CXX)
add_definitions(-D_SIZEOF_INT64_T=${SIZEOF_INT64_T})
check_type_size("uint64_t" SIZEOF_UINT64_T LANGUAGE CXX)
add_definitions(-D_SIZEOF_UINT64_T=${SIZEOF_UINT64_T})
check_type_size("intmax_t" SIZEOF_INTMAX_T LANGUAGE CXX)
add_definitions(-D_SIZEOF_INTMAX_T=${SIZEOF_INTMAX_T})
check_type_size("uintmax_t" SIZEOF_UINTMAX_T LANGUAGE CXX)
add_definitions(-D_SIZEOF_UINTMAX_T=${SIZEOF_UINTMAX_T})

file(GLOB ObjectMapper_SRCS_G src/JXXON/*.cpp src/${JXXON_IMPL}_impl/JXXON/*.cpp src/${JXXON_IMPL}_impl/JXXON/Accessor/*.cpp)
add_library(ObjectMapper ${ObjectMapper_SRCS_G})
add_library(${PROJECT_NAME}::ObjectMapper ALIAS ObjectMapper)
set_target_properties(ObjectMapper PROPERTIES OUTPUT_NAME jxxon DEBUG_POSTFIX d)

target_include_directories(ObjectMapper PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src/${JXXON_IMPL}_impl>
	$<BUILD_INTERFACE:${jxxon_impl_INCLUDE_DIRS}>
	$<INSTALL_INTERFACE:include>)
target_link_libraries(ObjectMapper Polymorphic::Containers ${jxxon_impl_LIBRARIES})

install(TARGETS ObjectMapper EXPORT JXXONTargets
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} FILES_MATCHING PATTERN "*.h")
install(EXPORT JXXONTargets NAMESPACE ${PROJECT_NAME}:: DESTINATION share/JXXON/cmake)
configure_file(cmake/${JXXON_IMPL}_impl/JXXONConfig.cmake.in JXXONConfig.cmake @ONLY)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/JXXONConfigVersion.cmake COMPATIBILITY SameMajorVersion)
install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/JXXONConfig.cmake
	${CMAKE_CURRENT_BINARY_DIR}/JXXONConfigVersion.cmake
	DESTINATION share/JXXON/cmake)

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

add_test(NAME SetTest COMMAND setTest)
add_dependencies(check setTest)

add_test(NAME MultisetTest COMMAND multisetTest)
add_dependencies(check multisetTest)

add_test(NAME UnorderedSetTest COMMAND unorderedSetTest)
add_dependencies(check unorderedSetTest)

add_test(NAME UnorderedMultisetTest COMMAND unorderedMultisetTest)
add_dependencies(check unorderedMultisetTest)

add_test(NAME MiscellaneousTest COMMAND miscellaneousTest)
add_dependencies(check miscellaneousTest)
