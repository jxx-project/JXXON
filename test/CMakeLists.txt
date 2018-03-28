#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:     BSL-1.0
#

find_package(Threads)

file(GLOB TEST_MODEL_SRCS_G Model/*.cpp)
add_library(model ${TEST_MODEL_SRCS_G})
target_include_directories(model PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(model jxxon)

add_executable(objectTest objectTest.cpp)
target_include_directories(objectTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(objectTest
	jxxon
	model
	${jxxon_impl_LIBRARIES}
	${CMAKE_THREAD_LIBS_INIT})
