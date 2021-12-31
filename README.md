# HOPE: Highly Operational Programming Enviroment

Numerical solution for linear (state-space form) and nonlinear systems using the Dormand-Prince 5 algorithm.

Numerical integration parameters such as initial time, final time, and step size can be modified at runtime from the main menu.

Results are exported as .txt files in the binary directory for both linear and nonlinear systems.

### Highlights
- Capable of solving systems with 1 to 6 (or more) state variables
- Capable of solving output equation by using the calculated state variables

### Requirements
- Build:
  - CMake

### Project Structure
- include/  (header files)
- libs/     (external libraries)
- src/      (source code files)
- python/   (Python scripts)

### External Libraries
- Boost: provides free peer-reviewed portable C++ source libraries
- Eigen: a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms
