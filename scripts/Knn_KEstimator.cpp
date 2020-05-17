//
// Created by igor on 16/05/2020.
//


#include <iostream>
#include "KnnKEstimator.h"

int main() {
    ClassificationType type = BINARY;
    Dataset train("train-sample", type);
    Dataset test("testa-sample", type);

    KnnKEstimator estimator(train, 15);
    estimator.rocCurve(test);

    return 0;
}