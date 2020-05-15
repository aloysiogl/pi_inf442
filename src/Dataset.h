//
// Created by igor on 15/05/2020.
//

#ifndef PI_INF442_DATASET_H
#define PI_INF442_DATASET_H

#include <vector>
#include "Token.h"

class Dataset {
public:
    Dataset();

    std::vector<Token> &getTokens();

private:
    std::vector<Token> tokens;
};


#endif //PI_INF442_DATASET_H
