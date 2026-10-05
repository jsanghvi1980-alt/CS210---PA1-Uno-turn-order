cmake_minimum_required(VERSION 3.20)

project(cs210_PA1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(CS210_PA1
        main.cpp
        Node.h
        List.h
        ArrayList.h
        LinkedList.h
        Player.h
)

target_compile_options(CS210_PA1 PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)