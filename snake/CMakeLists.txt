cmake_minimum_required(VERSION 3.19)
project(snake)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(snake
        apple.cpp
        check.cpp
        file.cpp
        game.cpp
        game_over.cpp
        getch.cpp
        header.h
        input.cpp
        main.cpp
        move.cpp
        print.cpp
        snake.cpp)
