cmake_minimum_required(VERSION 3.6)
project(concurrency_lib)


set(SRC     
        thread/thread_pool/ThreadPool.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})
target_include_directories(${CMAKE_PROJECT_NAME}      
                                            PUBLIC thread/
                                            PUBLIC atomic/
                                            PUBLIC mutex/)
                                