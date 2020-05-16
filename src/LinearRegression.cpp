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
            X(i, j) = dataset[i][j-1];
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

    MatrixXd Xt = X.transpose();

    B = (Xt*X).inverse()*Xt*Z;
}

Class LinearRegression::classify(Token &token) {
    RowVectorXd vec(dataset.dimension() + 1);
    for (int i = 1; i < dataset.dimension()+1; ++i)
        vec[i] = token[i-1];
    vec[0] = 1.0;

    RowVectorXd pred = vec*B;

    auto clf = (Class) 0;
    for (int i = 0; i < N_CLASSES; ++i)
        if (pred[i] > pred[(int) clf])
            clf = (Class) i;

    return clf;
}
