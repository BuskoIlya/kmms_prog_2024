cmake_minimum_required(VERSION 3.2...3.27.5)

project(parser)

add_subdirectory(lib/cpr)
add_subdirectory(lib/json)
add_subdirectory(src)

set(CMAKE_SUPPRESS_REGENERATION true)
