add_executable(${PROJECT_NAME} execution.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_NAME}_library)
