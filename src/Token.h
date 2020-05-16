//
// Created by igor on 15/05/2020.
//

#ifndef PI_INF442_TOKEN_H
#define PI_INF442_TOKEN_H

#include <vector>
#include "Class.h"

class Token {
public:
    Token();

    Token(std::vector<double> &v, Class c = UNDEFINED);

    std::vector<double> &getData();

    void setClass(Class c);

    Class getClass();

    int size() const;

    double& operator[](int idx);

    double dist(Token &t);

private:
    std::vector<double> v;
    Class c;
};


#endif //PI_INF442_TOKEN_H
