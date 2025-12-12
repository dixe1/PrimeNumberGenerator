cmake_minimum_required(VERSION 3.25)

project(Project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SRC_FILES
    src/*.cpp
)

add_executable(Project
    main.cpp
    ${SRC_FILES}
)