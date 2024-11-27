add_executable(${PROJECT_NAME} main.cpp req.cpp)

target_link_libraries(${PROJECT_NAME} 
	cpr 
	nlohmann_json 
)
