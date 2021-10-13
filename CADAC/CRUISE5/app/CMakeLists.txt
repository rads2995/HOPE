add_executable(${PROJECT_NAME} execution.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_library)
