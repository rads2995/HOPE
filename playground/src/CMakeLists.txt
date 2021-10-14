# Add source code for library and include respective header files
add_library(${PROJECT_NAME}_library simulate_system.cpp)
target_include_directories(${PROJECT_NAME}_library PUBLIC ../include)

# Add source executable and link to private source library
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_library)
