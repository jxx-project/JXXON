#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:     BSL-1.0
#


file(GLOB TEST_MODEL_SRCS_G Model/*.cpp)
add_library(model ${TEST_MODEL_SRCS_G})
target_include_directories(model PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(model ${PROJECT_NAME}::JXXON)

add_executable(objectTest objectTest.cpp)
target_include_directories(objectTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(objectTest
	${PROJECT_NAME}::JXXON
	model
	${jxxon_impl_LIBRARIES})

add_executable(vectorTest vectorTest.cpp)
target_include_directories(vectorTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(vectorTest
	${PROJECT_NAME}::JXXON
	model
	${jxxon_impl_LIBRARIES})

add_executable(listTest listTest.cpp)
target_include_directories(listTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(listTest
	${PROJECT_NAME}::JXXON
	model
	${jxxon_impl_LIBRARIES})

add_executable(mapTest mapTest.cpp)
target_include_directories(mapTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(mapTest
	${PROJECT_NAME}::JXXON
	model
	${jxxon_impl_LIBRARIES})

add_executable(unorderedMapTest unorderedMapTest.cpp)
target_include_directories(unorderedMapTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(unorderedMapTest
	${PROJECT_NAME}::JXXON
	model
	${jxxon_impl_LIBRARIES})

add_executable(miscellaneousTest miscellaneousTest.cpp)
target_include_directories(miscellaneousTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(miscellaneousTest
	${PROJECT_NAME}::JXXON
	model
	${jxxon_impl_LIBRARIES})
