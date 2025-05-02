cmake_minimum_required(VERSION 3.2...3.27.5)

project(students)

SET(CMAKE_CXX_FLAGS "-finput-charset=utf-8 -fexec-charset=utf-8")

SET(SQLITE_LIB "sqlite_lib")
SET(APP "students_journal")

add_subdirectory(lib/sqlite)
add_subdirectory(src)
