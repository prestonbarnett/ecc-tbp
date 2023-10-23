cmake_minimum_required(VERSION 3.26)
project(ecctbp)

set(CMAKE_CXX_STANDARD 17)

add_library(ecctbp
        FieldElement.cpp
        FieldElement.h
        PointInteger.cpp
        PointInteger.h
        PointFieldElement.cpp
        PointFieldElement.h
        S256Field.cpp
        S256Field.h
        S256Point.cpp
        S256Point.h
        Signature.cpp
        Signature.h
        PrivateK.cpp
        PrivateK.h)

find_package(cryptopp)

target_link_libraries(ecctbp cryptopp::cryptopp)

add_subdirectory(tests)
