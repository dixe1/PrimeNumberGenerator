cmake_minimum_required(VERSION 3.25)

project(ToDoList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SRC_FILES
    include/*.cpp
)

add_executable(todolist
    main.cpp
    ${SRC_FILES}
)