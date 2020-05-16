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

    explicit Token(std::vector<float> &v, Class c = UNDEFINED);

    std::vector<float> &getData();

    void setClass(Class c);

    Class getClass();

    int size() const;

    float& operator[](int idx);

    float dist(Token &t);

private:
    std::vector<float> v;
    Class c;
};

std::ostream &operator<<(std::ostream &os, Token &t);


#endif //PI_INF442_TOKEN_H
