cmake_minimum_required(VERSION 3.26)
project(biginteger C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(biginteger
        main.c
        bigint.c
        bigint.h)
