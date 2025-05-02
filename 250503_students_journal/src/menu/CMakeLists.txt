target_sources(${APP} 
	PRIVATE
		menu_functions.cpp
		menu_items.cpp
)

target_include_directories(${APP} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
