cmake_minimum_required(VERSION 3.15)
project(CPP-ALGORITHMS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# VCPKG: только если файл существует (игнорируется на Linux)
find_file(VCPKG_TOOLCHAIN 
    "C:/dev/Libraries/vcpkg/scripts/buildsystems/vcpkg.cmake"
    NO_DEFAULT_PATH
)
if(VCPKG_TOOLCHAIN)
    message(STATUS "Using vcpkg: ${VCPKG_TOOLCHAIN}")
    set(CMAKE_TOOLCHAIN_FILE ${VCPKG_TOOLCHAIN} CACHE STRING "" FORCE)
endif()

add_library(algorithms INTERFACE)
target_include_directories(algorithms INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

# Универсальный поиск GTest
find_package(GTest CONFIG QUIET)
if(TARGET GTest::gtest)
    # vcpkg/Windows - таргеты
    message(STATUS "GTest found via CONFIG (vcpkg)")
    set(GTEST_LINK_LIBS GTest::gtest GTest::gtest_main)
    set(GTEST_INCLUDES "")
elseif()
    # Linux/legacy - модуль
    find_package(GTest REQUIRED)
    message(STATUS "GTest found via MODULE (system)")
    set(GTEST_LINK_LIBS ${GTEST_BOTH_LIBRARIES})
    target_include_directories(test_linear_search PRIVATE ${GTEST_INCLUDE_DIRS})
endif()

add_executable(test_linear_search tests/search/test_linear_search.cpp)
target_link_libraries(test_linear_search PRIVATE 
    algorithms 
    ${GTEST_LINK_LIBS}
)

add_test(NAME test_linear_search COMMAND test_linear_search)
