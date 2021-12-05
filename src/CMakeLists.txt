# Add library for source code header files
add_library(Library main.cpp)
target_include_directories(Library PUBLIC ../include ../lib)

# Add source executable and link to library
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Library)
