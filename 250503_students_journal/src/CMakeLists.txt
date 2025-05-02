add_executable(${APP} main.cpp)

add_subdirectory(db)
add_subdirectory(io)
add_subdirectory(menu)

target_link_libraries(${APP} ${SQLITE_LIB})
