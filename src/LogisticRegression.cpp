//
// Created by Aloysio Galvão Lopes on 2020-05-16.
//

#include "LogisticRegression.h"
#include <iostream>

LogisticRegression::LogisticRegression(Dataset &dataset, int MAX_ITER) : Classifier(dataset) {
    this->MAX_ITER = MAX_ITER;
    train();
}

void LogisticRegression::train() {
    // Initializing b vector
    b.resize(dataset.dimension()+1);
    b.setZero();

    MatrixXd X(dataset.size(), dataset.dimension()+1);

    // Reading data and transferring to observation matrix
    for (int i = 0; i < dataset.size(); ++i){
        for (int j = 1; j < dataset.dimension()+1; ++j)
            X(i, j) = dataset[i][j-1];
        X(i, 0) = 1.0;
    }

    VectorXd z(dataset.size());

    for(int i = 0; i < z.size(); ++i){
        if (dataset[i].getClass() == 1)
            z[i] = 1.0;
        else z[i] = 0.0;
    }


    for (int i = 0; i < MAX_ITER; ++i){
        VectorXd beta = b;
        b = beta - lapla(beta, X).inverse()*grad(beta, z, X);
        std::cout << "Iteration: " << i+1 << " of " << MAX_ITER << "\n";
    }
}

double LogisticRegression::sig(double x) {
    return 1/(1+exp(-x));
}

Class LogisticRegression::classify(Token &token) {
    RowVectorXd vec(dataset.dimension() + 1);
    for (int i = 1; i < dataset.dimension()+1; ++i)
        vec[i] = token[i-1];
    vec[0] = 1.0;

    double p1 = sig(vec*b);

    if (p1 >= 0.5)
        return (Class) 1;
    return  (Class) 0;
}

VectorXd LogisticRegression::grad(VectorXd &beta, VectorXd &z, MatrixXd &X) {
    VectorXd sum(dataset.dimension()+1);
    sum.setZero();

    for (int i = 0; i < dataset.size(); ++i){
        sum += (z[i]-sig(X.row(i)*beta))*(X.row(i).transpose());
    }

    return sum;
}

MatrixXd LogisticRegression::lapla(VectorXd &beta, MatrixXd &X) {
    MatrixXd sum(dataset.dimension()+1, dataset.dimension()+1);
    sum.setZero();

    for (int i = 0; i < dataset.size(); ++i){
        double prob = sig(X.row(i)*beta);
        sum += prob*(1-prob)*((X.row(i).transpose())*X.row(i));
    }
    return -sum;
}

double LogisticRegression::classificationProbability(Class c, Token& token) {
    RowVectorXd vec(dataset.dimension() + 1);
    for (int i = 1; i < dataset.dimension()+1; ++i)
        vec[i] = token[i-1];
    vec[0] = 1.0;

    double p1 = sig(vec*b);

    if ((int) c == 0)
        return 1-p1;
    return p1;
}
