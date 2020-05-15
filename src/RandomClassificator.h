//
// Created by igor on 15/05/2020.
//

#ifndef PI_INF442_RANDOMCLASSIFICATOR_H
#define PI_INF442_RANDOMCLASSIFICATOR_H

#include <random>
#include "Classificator.h"

class RandomClassificator : public Classificator {
public:
    explicit RandomClassificator(Dataset &trainDataset);

    Class classify(Token &token) override;

private:
    std::default_random_engine state;
    std::uniform_int_distribution<int> distribution;
};


#endif //PI_INF442_RANDOMCLASSIFICATOR_H
