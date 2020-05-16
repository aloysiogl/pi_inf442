//
// Created by igor on 15/05/2020.
//

#ifndef PI_INF442_DATASET_H
#define PI_INF442_DATASET_H

#include <vector>
#include <string>
#include "Token.h"

enum ClassificationType {
    BINARY, NER
};

class Dataset {
public:
    explicit Dataset(const std::string &dataFile, const std::string &labelFile, ClassificationType type = NER);

    std::vector<Token> &getTokens();

    Token &getToken(int i);

    int getSize() const;

    int getDimension() const;

    ClassificationType getType() const;

private:
    std::vector<Token> tokens;
    ClassificationType type;
};


#endif //PI_INF442_DATASET_H
