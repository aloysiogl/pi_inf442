//
// Created by igor on 16/05/2020.
//

#ifndef PI_INF442_KNNCLASSIFIER_H
#define PI_INF442_KNNCLASSIFIER_H

#include "Classifier.h"
#include "ann_1.1.2/include/ANN/ANN.h"

class KnnClassifier : public Classifier {
public:
    explicit KnnClassifier(Dataset &trainDataset, int k);

    Class classify(Token &token) override;

private:
    ANNkd_tree tree;
    int k;
};


#endif //PI_INF442_KNNCLASSIFIER_H
