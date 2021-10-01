add_library(${PROJECT_NAME}_library 
            class_functions.cpp cruise_modules.cpp satellite_functions.cpp
            target_modules.cpp global_functions.cpp satellite_modules.cpp
            utility_functions.cpp cruise_functions.cpp round3_modules.cpp
            target_functions.cpp)
target_include_directories(${PROJECT_NAME}_library PUBLIC ../include)
