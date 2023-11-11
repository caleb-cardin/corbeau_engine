cmake_minimum_required(VERSION 3.26)


project(corbeau_engine)


set(CMAKE_CXX_STANDARD 20)


find_package(glfw3 CONFIG REQUIRED)


add_subdirectory(corbeau)
add_subdirectory(colibri)

add_library(glad lib/glad/include/glad/gl.h lib/glad/src/gl.c)
target_include_directories(glad PUBLIC lib/glad/include)
