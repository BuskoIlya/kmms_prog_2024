target_sources(${APP} 
	PRIVATE
		students_db.cpp
)

target_include_directories(${APP} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
