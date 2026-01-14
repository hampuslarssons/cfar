cmake_minimum_required(VERSION 3.16)

project(
    cfar
    VERSION 0.1.0
    DESCRIPTION "Header-only CFAR algorithms for radar signal processing"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(cfar INTERFACE)

target_include_directories(
    cfar
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(
    cfar
    INTERFACE
        cxx_std_20
)

target_compile_options(
    cfar
    INTERFACE
        $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
)

option(CFAR_BUILD_TESTS "Build CFAR unit tests" OFF)

if (CFAR_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

option(CFAR_BUILD_EXAMPLES "Build CFAR examples" OFF)

if (CFAR_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
