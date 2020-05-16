//
// Created by igor on 15/05/2020.
//

#ifndef PI_INF442_DATASET_H
#define PI_INF442_DATASET_H

#include <vector>
#include <fstream>
#include <string>
#include "Token.h"

enum ClassificationType {
    BINARY, NER
};

class Dataset {
public:
    explicit Dataset(const std::string &name, ClassificationType type = NER);

    std::vector<Token> &getTokens();

    int size() const;

    int dimension() const;

    ClassificationType getType() const;

    Token& operator[](int idx);

private:
    std::vector<Token> tokens;
    ClassificationType type;

    void loadNpy(const std::string &name);

    void loadCsv(const std::string &name);
};


#endif //PI_INF442_DATASET_H
