cruise5: class_functions.o cruise_functions.o cruise_modules.o execution.o global_functions.o round3_modules.o satellite_functions.o satellite_modules.o target_functions.o target_modules.o utility_functions.o
	g++ class_functions.o cruise_functions.o cruise_modules.o execution.o global_functions.o round3_modules.o satellite_functions.o satellite_modules.o target_functions.o target_modules.o utility_functions.o -o cruise5

class_functions.o: class_functions.cpp
	g++ -c class_functions.cpp

cruise_functions.o: cruise_functions.cpp
	g++ -c cruise_functions.cpp

cruise_modules.o: cruise_modules.cpp
	g++ -c cruise_modules.cpp

execution.o: execution.cpp
	g++ -c execution.cpp

global_functions.o: global_functions.cpp
	g++ -c global_functions.cpp

round3_modules.o: round3_modules.cpp
	g++ -c round3_modules.cpp

satellite_functions.o: satellite_functions.cpp
	g++ -c satellite_functions.cpp

satellite_modules.o: satellite_modules.cpp
	g++ -c satellite_modules.cpp

target_functions.o: target_functions.cpp
	g++ -c target_functions.cpp

target_modules.o: target_modules.cpp
	g++ -c target_modules.cpp

utility_functions.o: utility_functions.cpp
	g++ -c utility_functions.cpp

clean:
	rm *.o