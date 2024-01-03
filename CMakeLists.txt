cmake_minimum_required(VERSION 3.27)


project(corbeau_engine)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API  "aa1f7df0-828a-4fcd-9afc-2dc80491aca7")


find_package(glfw3 CONFIG REQUIRED)


add_subdirectory(corbeau)
add_subdirectory(colibri)


