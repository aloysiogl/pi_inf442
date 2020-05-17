//
// Created by igor on 16/05/2020.
//

#ifndef PI_INF442_KNNKESTIMATOR_H
#define PI_INF442_KNNKESTIMATOR_H

#include "KnnClassifier.h"

class KnnKEstimator {
public:
    KnnKEstimator(Dataset &trainDataset, int maxK);

    std::vector<std::pair<int, int>> rocCurve(Dataset &testDataset);

private:
    Dataset &dataset;
    int maxK;
};


#endif //PI_INF442_KNNKESTIMATOR_H
