cmake_minimum_required(VERSION 3.15)
project(cpp11test)

set(CMAKE_CXX_STANDARD 11)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(cpp11test
        src/SmartPtrTests.cpp
        src/TestClasses.cpp)