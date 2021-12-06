# HOPE: Highly Operational Programming Enviroment

Numerical simulation for LTI state-space systems using the Dormand-Prince 5 algorithm.

Can solve systems with 1 to 6 state variables. Higher number of state variables requires modification of main.cpp source file. 

Numerical integration parameters such as initial time, final time, and step size can be modified at runtime from the main menu.

Results are exported as .txt files in the binary directory for both the state vectors and output vector.

### Highlights
- Capable of solving systems with 1 to 6 (or more) state variables
- Capable of solving output equation by using the calculated state variables
- State-Space system's matrices and vectors are loaded from .txt files inside of /data directory
- State-space system's matrices and vectors can be resized and edited while program is running

### Requirements
- Build:
  - CMake
<br/><br/>
- Optional:
  - Numpy
  - Matplotlib
  - PyInstaller

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
