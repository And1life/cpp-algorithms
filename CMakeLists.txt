cmake_minimum_required(VERSION 3.15)
project(CPP-ALGORITHMS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_file(VCPKG_TOOLCHAIN 
    "C:/dev/Libraries/vcpkg/scripts/buildsystems/vcpkg.cmake"
    NO_DEFAULT_PATH
)
if(VCPKG_TOOLCHAIN)
    message(STATUS "Using vcpkg: ${VCPKG_TOOLCHAIN}")
    set(CMAKE_TOOLCHAIN_FILE ${VCPKG_TOOLCHAIN} CACHE STRING "" FORCE)
endif()

add_library(algorithms INTERFACE)
target_include_directories(algorithms 
    INTERFACE 
        ${CMAKE_CURRENT_SOURCE_DIR}/include)


enable_testing()

find_package(GTest CONFIG QUIET)
if(TARGET GTest::gtest)
    message(STATUS "GTest found via CONFIG (vcpkg)")
    set(GTEST_LINK_LIBS GTest::gtest GTest::gtest_main)
else()
    find_package(GTest REQUIRED)
    message(STATUS "GTest found via MODULE (system)")
    set(GTEST_LINK_LIBS GTest::gtest GTest::gtest_main)
endif()

set(TEST_SOURCES
    tests/search/test_linear_search.cpp
    tests/search/test_binary_search.cpp
    # tests/sorting/test_quick_sort.cpp
    # tests/graph/test_dijkstra.cpp
)

add_executable(tests ${TEST_SOURCES})

target_link_libraries(tests
    PRIVATE
        algorithms
        ${GTEST_LINK_LIBS}
)

add_test(NAME cpp_algorithms_tests COMMAND tests)
