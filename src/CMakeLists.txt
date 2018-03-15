#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:     BSL-1.0
#

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${JXXON_IMPL}_impl)
file(GLOB SRCS_G JXXON/*.cpp ${JXXON_IMPL}_impl/*.cpp ${JXXON_IMPL}_impl/JXXON/*.cpp ${JXXON_IMPL}_impl/JXXON/Accessor/*.cpp)

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

add_library(jxxon ${SRCS_G} ${IMPL_SRCS_G})

set_target_properties(jxxon PROPERTIES PUBLIC_HEADER "JXXON/Error.h;JXXON/Json.h;JXXON/List.h;JXXON/Map.h;JXXON/Serializable.h;JXXON/UnorderedMap.h;JXXON/Vector.h")

install(TARGETS jxxon
	ARCHIVE DESTINATION lib COMPONENT lib
	PUBLIC_HEADER DESTINATION include/JXXON COMPONENT dev)
