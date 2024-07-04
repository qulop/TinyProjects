cmake_minimum_required(VERSION 3.5)
project("locateof")

set(SRC src/main.c)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC src/)
