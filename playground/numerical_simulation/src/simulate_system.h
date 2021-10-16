// Class for simulating linear state-space model
// {x}(k+1) = [A]{x}(k) + [B]{u}(k)
//   {y}(k) = [C]{x}(k)
//
// Start from initial state vector {x0}

#ifndef SIMULATE_SYSTEM_H
#define SIMULATE_SYSTEM_H

#include <iostream>
#include <Eigen/Dense>

class SimulateSystem {
private:
    
    int m, n, r, time_samples;

    Eigen::MatrixXd A;
    Eigen::MatrixXd B;
    Eigen::MatrixXd C;

    Eigen::MatrixXd x0;

    Eigen::MatrixXd input_sequence;
    Eigen::MatrixXd simulated_state_sequence;
    Eigen::MatrixXd simulated_output_sequence;
    Eigen::MatrixXd time_row_vector;

public:
    
    SimulateSystem();
    ~SimulateSystem();
    

};

#endif // SIMULATE_SYSTEM_H
