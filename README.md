# HOPE: Highly Operational Programming Enviroment

Numerical simulation of dynamical systems.

Various parameters can be changed in the include/constants.h header file.

### Libraries
- Boost (odeint)
- Eigen (Core)

### Requirements
- CMake (build)

### Project Structure
- include/  (header files)
- lib/      (external libraries)
- python/   (python scripts, requires Numpy and Matplotlib)
- src/      (source code files)

### To-Do
- Read state matrices and vectors from text file (simulate_system.cpp)
- User can modify components of state matrices and vectors before running
  simulation
- Custom state matrices and vectors for those with more complicated
  formulations (i.e. variables, long or complicated elements)
- Implement various stepper and integrator methods (only Runge-Kutta
  Dormand-Prince 5 method with equidistant integration for now...)

### Questions
Email me at: Rads2995@gmail.com
