#include "simulate_system.hpp"

SimulateSystem::SimulateSystem() {

    m = 0; n = 0; r = 0;
    A.resize(1, 1); A.setZero();
    B.resize(1, 1); B.setZero(); 
    C.resize(1, 1); C.setZero();
    x0.resize(1, 1); x0.setZero();
    inputSequence.resize(1, 1); inputSequence.setZero(); 
    simulatedStateSequence.resize(1, 1); simulatedStateSequence.setZero();
    simulatedOutputSequence.resize(1, 1); simulatedOutputSequence.setZero();    
    timeRowVector.resize(1, 1); timeRowVector.setZero();   
}

SimulateSystem::SimulateSystem(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd C, Eigen::MatrixXd x0, Eigen::MatrixXd inputSequence) {

    this->A = A;
    this->B = B;
    this->C = C;
    this->x0 = x0;
    this->inputSequence = inputSequence;

    n = A.rows();
    m = B.cols();
    r = C.rows();

    timeSamples = inputSequence.cols();

}
