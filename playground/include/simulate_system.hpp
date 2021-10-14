#ifndef HOPE_SIMULATE_SYSTEM_HPP
#define HOPE_SIMULATE_SYSTEM_HPP

#include <Eigen/Dense>
#include <tuple>

class SimulateSystem {
private:
    Eigen::MatrixXd A, B, C;
    Eigen::MatrixXd x0;
    Eigen::MatrixXd inputSequence;
    Eigen::MatrixXd simulatedStateSequence;
    Eigen::MatrixXd simulatedOutputSequence;
    Eigen::MatrixXd timeRowVector;

    int m, n, r, timeSamples;

public:

    SimulateSystem();

    SimulateSystem(Eigen::MatrixXd A, Eigen::MatrixXd B, Eigen::MatrixXd C, Eigen::MatrixXd x0, Eigen::MatrixXd inputSequence);

    ~SimulateSystem();

    std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> getStateOutputTime();

    void runSimulation();
};

#endif  // HOPE_SIMULATE_SYSTEM_HPP
