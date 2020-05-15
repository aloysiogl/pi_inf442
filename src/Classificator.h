//
// Created by igor on 15/05/2020.
//

#ifndef PI_INF442_CLASSIFICATOR_H
#define PI_INF442_CLASSIFICATOR_H

#include "Class.h"
#include "Dataset.h"

class Classificator {
public:
    explicit Classificator(Dataset &dataset);

    virtual Class classify(Token &token) = 0;

private:
    Dataset &dataset;
};


#endif //PI_INF442_CLASSIFICATOR_H
