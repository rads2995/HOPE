// global_constants.hpp: Header file containing global constant parameters.
#pragma once

namespace constants {
    inline constexpr double REARTH = 6370987.308;       // Mean earth radius [m]
    inline constexpr double WEII3 = 7.292115e-5;	    // Angular rotation of earth [rad/s]
    inline constexpr double RAD = 0.0174532925199432;	// Conversion factor [deg->rad]
    inline constexpr double DEG = 57.2957795130823;		// Conversion factor [rad->deg]
    inline constexpr double AGRAV = 9.80675445;			// Standard value of gravity acceleration [m/s^2] 
    inline constexpr double G = 6.673e-11;				// Universal gravitational constant [Nm^2/kg^2] 
    inline constexpr double EARTH_MASS = 5.973e24;		// Mass of the earth [kg] 
    inline constexpr double R = 287.053;				// Ideal gas constant [m^2/(K*s^2)] 
    inline constexpr double PI = 3.1415927;				// Circumference of unit diameter circle
    inline constexpr double EPS = 1e-10;				// Machine precision error
    inline constexpr double SMALL = 1.e-7;				// Small real number
    inline constexpr int ILARGE = 9999;					// Large integer number
    inline constexpr double BIG = 1e10;					// Big number
    
    // Sizing of arrays
    inline constexpr int CHARN = 40;					// Character numbers in variable names
    inline constexpr int CHARL = 150;					// Character numbers in a line

    // Verify the following array sizes. If too
    // small, dynamic memory allocations may fail!
    inline constexpr int NROUND3 = 40;					// Size of "round3" module-variable array
    inline constexpr int NCRUISE = 160;					// Size of "cruise" module-variable array 
    inline constexpr int NTARGET = 20;					// Size of "target" module-variable array
    inline constexpr int NSATELLITE = 20;				// Size of "satellite" module-variable array
    inline constexpr int NEVENT = 25;					// Max number of events
    inline constexpr int NVAR = 15;						// Max number of variables to be input at every event 
}
