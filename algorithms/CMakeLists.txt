cmake_minimum_required(VERSION 3.6)
project(c_algo)

set(SRC
        main.c
        linked_list/list.c)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC linked_list/)
