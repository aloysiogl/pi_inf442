//
// Created by Aloysio Galvão Lopes on 2020-05-16.
//

#ifndef PI_INF442_LINEARREGRESSION_H
#define PI_INF442_LINEARREGRESSION_H


#include "Classifier.h"
#include <Eigen/Dense>

using Eigen::MatrixXf;
using Eigen::VectorXf;
using Eigen::RowVectorXf;

class LinearRegression : public Classifier {
public:
    LinearRegression(Dataset& dataset);

    LinearRegression(Dataset& dataset, std::vector<Class> &classes);

    Class classify(Token& token);

    float classificationProbability(Class c, Token &token);

private:
    void train();

    MatrixXf B;
    std::vector<Class> classes;
};


#endif //PI_INF442_LINEARREGRESSION_H
