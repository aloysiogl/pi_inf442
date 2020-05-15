//
// Created by igor on 15/05/2020.
//

#ifndef PI_INF442_CLASSIFICATOR_H
#define PI_INF442_CLASSIFICATOR_H

#include "Class.h"
#include "Dataset.h"

class Classificator {
public:
    explicit Classificator(Dataset &trainDataset);

    virtual Class classify(Token &token) = 0;

    virtual std::vector<Class> classify(Dataset &testDataset);

private:
    Dataset &dataset;
};


#endif //PI_INF442_CLASSIFICATOR_H
