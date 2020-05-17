//
// Created by Aloysio Galvão Lopes on 2020-05-16.
//

#ifndef PI_INF442_LOGISTICREGRESSION_H
#define PI_INF442_LOGISTICREGRESSION_H


#include "Classifier.h"
#include <Eigen/Dense>

using Eigen::VectorXf;
using Eigen::RowVectorXf;
using Eigen::MatrixXf;

class LogisticRegression : public Classifier {
public:
    LogisticRegression(Dataset& dataset, int MAX_ITER = 10);

    LogisticRegression(Dataset& dataset, std::vector<Class> &classes, int MAX_ITER = 10);

    Class classify(Token& token);

    float classificationProbability(Class c, Token& token);

private:
    void train();
    float sig(float x);
    VectorXf grad(VectorXf& b, VectorXf& z, MatrixXf& X);
    MatrixXf lapla(VectorXf &beta, MatrixXf &X);

    std::vector<Class> classes;
    VectorXf b;
    int MAX_ITER;
};


#endif //PI_INF442_LOGISTICREGRESSION_H
