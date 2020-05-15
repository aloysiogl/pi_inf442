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

    void setClass(Class c);

    Class getClass();

private:
    std::vector<double> v;
    Class c;
};


#endif //PI_INF442_TOKEN_H
