target_sources(${APP} 
	PRIVATE
		io.cpp
)

target_include_directories(${APP} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
