# Copyright 2022 Cantab Research Ltd.
# Licensed under the MIT license. See LICENSE.txt in the project root for details.

cmake_minimum_required(VERSION 3.20)

project(Pipelining_Coroutines)

find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-fcoroutines")

if(${CMAKE_CXX_COMPILER_ID} MATCHES "GNU")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "10.2.0")
        message(FATAL_ERROR "gcc version ${CMAKE_CXX_COMPILER_VERSION} is unsupported, please upgrade to at least 10.2.0. This is due to libcoro's requirements.")
    endif()
elseif(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
    message(FATAL_ERROR "Clang is currently not supported. This is due to libcoro's requirements.")
endif()

set(target_sources
        main.cpp
)

list(TRANSFORM target_sources PREPEND "src/")

add_executable(pc ${target_sources})

target_include_directories(pc PUBLIC 3rd_party/libcoro/inc 3rd_party/libcoro/vendor/tartanllama/expected/inc)

set(target_static_dependencies
        liblibcoro.a
)

list(TRANSFORM target_static_dependencies PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/lib/)

target_link_libraries(pc PUBLIC Threads::Threads ${target_static_dependencies})
