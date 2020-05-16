//
// Created by Aloysio Galvão Lopes on 2020-05-16.
//

#include "LinearRegression.h"

LinearRegression::LinearRegression(Dataset &dataset) : Classifier(dataset) {

}

void LinearRegression::train() {
    MatrixXd X(dataset.size(), dataset.size()+1);

    // Reading data and transferring to observation matrix
//    for (int i = 0; i < dataset.size(); ++i){
//        for (int j = 1; j < dataset.getDimension()+1; ++j)
//            X(i, j) = dataset.getToken(i)[]
//    }
}
