cmake_minimum_required(VERSION 3.26)
project(google_tests)

set(CMAKE_CXX_STANDARD 17)

add_executable(google_tests_run main.cpp
        FieldElementTest.cpp
        PointTest.cpp
        ECCTest.cpp
        S256FieldTest.cpp
        S256Test.cpp
        PrivateKTest.cpp)

find_package(GTest)

include_directories(${ecctbp_SOURCE_DIR})

target_link_libraries(google_tests_run ecctbp gtest::gtest)