#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:	BSL-1.0
#


file(GLOB Model_SRCS_G Model/*.cpp)
add_library(Model ${Model_SRCS_G})
target_include_directories(Model PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(Model ${PROJECT_NAME}::ObjectMapper)

add_executable(objectTest objectTest.cpp)
target_include_directories(objectTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(objectTest
	${PROJECT_NAME}::ObjectMapper
	Model
	${jxxon_impl_LIBRARIES})

add_executable(vectorTest vectorTest.cpp)
target_include_directories(vectorTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(vectorTest
	${PROJECT_NAME}::ObjectMapper
	Model
	${jxxon_impl_LIBRARIES})

add_executable(listTest listTest.cpp)
target_include_directories(listTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(listTest
	${PROJECT_NAME}::ObjectMapper
	Model
	${jxxon_impl_LIBRARIES})

add_executable(mapTest mapTest.cpp)
target_include_directories(mapTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(mapTest
	${PROJECT_NAME}::ObjectMapper
	Model
	${jxxon_impl_LIBRARIES})

add_executable(unorderedMapTest unorderedMapTest.cpp)
target_include_directories(unorderedMapTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(unorderedMapTest
	${PROJECT_NAME}::ObjectMapper
	Model
	${jxxon_impl_LIBRARIES})

add_executable(setTest setTest.cpp)
target_include_directories(setTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(setTest
	${PROJECT_NAME}::ObjectMapper
	Model
	${jxxon_impl_LIBRARIES})

add_executable(multisetTest multisetTest.cpp)
target_include_directories(multisetTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(multisetTest
	${PROJECT_NAME}::ObjectMapper
	Model
	${jxxon_impl_LIBRARIES})

add_executable(unorderedSetTest unorderedSetTest.cpp)
target_include_directories(unorderedSetTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(unorderedSetTest
	${PROJECT_NAME}::ObjectMapper
	Model
	${jxxon_impl_LIBRARIES})

add_executable(unorderedMultisetTest unorderedMultisetTest.cpp)
target_include_directories(unorderedMultisetTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(unorderedMultisetTest
	${PROJECT_NAME}::ObjectMapper
	Model
	${jxxon_impl_LIBRARIES})

add_executable(miscellaneousTest miscellaneousTest.cpp)
target_include_directories(miscellaneousTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(miscellaneousTest
	${PROJECT_NAME}::ObjectMapper
	Model
	${jxxon_impl_LIBRARIES})
