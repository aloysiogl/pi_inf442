//
// Created by Aloysio Galvão Lopes on 2020-05-16.
//

#ifndef PI_INF442_LOGISTICREGRESSION_H
#define PI_INF442_LOGISTICREGRESSION_H


#include "Classifier.h"
#include <Eigen/Dense>

using Eigen::VectorXd;
using Eigen::RowVectorXd;
using Eigen::MatrixXd;

class LogisticRegression : public Classifier {
public:
    LogisticRegression(Dataset& dataset);

    Class classify(Token& token);


private:
    void train();
    double sig(double x);
    VectorXd grad(VectorXd& b, VectorXd& z, MatrixXd& X);
    MatrixXd lapla(VectorXd &beta, MatrixXd &X);
    VectorXd b;
};


#endif //PI_INF442_LOGISTICREGRESSION_H
