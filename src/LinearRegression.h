//
// Created by Aloysio Galvão Lopes on 2020-05-16.
//

#ifndef PI_INF442_LINEARREGRESSION_H
#define PI_INF442_LINEARREGRESSION_H


#include "Classificator.h"
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class LinearRegression : public Classificator {
public:
    LinearRegression(Dataset& dataset);

private:
    void train();

    MatrixXd B;
};


#endif //PI_INF442_LINEARREGRESSION_H
