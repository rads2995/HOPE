# HOPE: Highly Operational Programming Enviroment

Numerical simulation for LTI state-space systems.

Can solve systems with 1-6 number of states. Higher number of states requires modification of main.cpp source file. 

Simulation parameters such as initial time, final time, and integration step size can be modified at runtime.

### What's Good
- System's matrices and vectors can be resized at runtime
- System's matrices can be read from text files inside of data directory
- Matrices' elements can be modified at runtime

### What is Not
- Higher number of states requires modification of source code
- No documentation on how to use this application

### Requirements
- Build:
  - CMake
<br/><br/>
- Optional:
  - Numpy
  - Matplotlib

### Project Structure
- include/  (header files)
- lib/      (external libraries)
- python/   (python scripts)
- src/      (source code files)

### External Libraries
- Boost: provides free peer-reviewed portable C++ source libraries
  - odeint: a library for solving initial value problems (IVP) of ordinary differential equations
<br/><br/>
- Eigen: a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms
  - Core: includes Matrix and Array classes, basic linear algebra (including triangular and selfadjoint products), array manipulation
