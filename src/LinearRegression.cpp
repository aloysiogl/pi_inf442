//
// Created by Aloysio Galvão Lopes on 2020-05-16.
//

#include "LinearRegression.h"
#include <iostream>

LinearRegression::LinearRegression(Dataset &dataset) : Classifier(dataset) {
    train();
}

void LinearRegression::train() {
    MatrixXd X(dataset.size(), dataset.dimension()+1);

    // Reading data and transferring to observation matrix
    for (int i = 0; i < dataset.size(); ++i){
        for (int j = 1; j < dataset.dimension()+1; ++j)
            X(i, j) = dataset[i][j];
        X(i, 0) = 1.0;
    }

    MatrixXd Z(dataset.size(), (int) N_CLASSES);
    Z.setZero();

    for (int i = 0; i < dataset.size(); ++i){
        for (int j = 0; j < (int) N_CLASSES; ++j){
            if ((int) dataset[i].getClass() == j){
                Z(i, j) = 1.0;
            }
        }
    }

//    X.rowwise().normalize();

//    MatrixXd Xt = X.transpose();

//    B.resize(dataset.dimension()+1, (int) N_CLASSES);

//    B = (Xt*X).inverse()*Xt;
//    MatrixXd I(dataset.dimension()+1, dataset.dimension()+1);
//    I.setIdentity();

//    std::cout << I;
//    std::cout << (Xt*X).determinant();
    std::cout << X;

//    std::cout << (Xt*X+I).inverse();
}

Class LinearRegression::classify(Token &token) {
    return UNDEFINED;
}
