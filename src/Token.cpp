//
// Created by igor on 15/05/2020.
//

#include <cmath>
#include "Token.h"

Token::Token() {
    c = UNDEFINED;
}

Token::Token(std::vector<double> &v, Class c) {
    this->v = v;
    this->c = c;
}

std::vector<double> & Token::getData() {
    return v;
}

void Token::setClass(Class c) {
    this->c = c;
}

Class Token::getClass() {
    return c;
}

int Token::size() const {
    return v.size();
}

double &Token::operator[](int idx) {
    return v[idx];
}

double Token::dist(Token &t) {
    double d = 0.0;
    for (int i = 0; i < size(); i++)
        d += (v[i] - t[i]) * (v[i] - t[i]);
    return std::sqrt(d);
}
