cmake_minimum_required(VERSION 3.9)
project(PreBuilt C)

set(CMAKE_C_STANDARD 99)

add_executable(PreBuilt main.c a.h b.h)