//
// Created by igor on 15/05/2020.
//

#ifndef PI_INF442_RANDOMCLASSIFIER_H
#define PI_INF442_RANDOMCLASSIFIER_H

#include <random>
#include "Classifier.h"

class RandomClassifier : public Classifier {
public:
    explicit RandomClassifier(Dataset &trainDataset);

    Class classify(Token &token) override;

private:
    std::uniform_int_distribution<int> distribution;
    std::default_random_engine state;
};


#endif //PI_INF442_RANDOMCLASSIFIER_H
