cmake_minimum_required(VERSION 3.10)
project(CPP-ALGORITHMS)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(GTest REQUIRED)


add_library(algorithms INTERFACE)
target_include_directories(algorithms
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)


enable_testing()


add_executable(test_linear_search
    tests/search/test_linear_search.cpp
)

target_link_libraries(test_linear_search
    PRIVATE
        algorithms
        GTest::gtest
        GTest::gtest_main
)



add_test(NAME test_linear_search COMMAND test_linear_search)
