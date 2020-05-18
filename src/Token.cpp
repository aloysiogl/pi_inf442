//
// Created by igor on 15/05/2020.
//

#include <iostream>
#include <cmath>
#include "Token.h"

Token::Token() {
    c = UNDEFINED;
}

Token::Token(std::vector<float> &v, Class c) {
    this->v = v;
    this->c = c;
}

std::vector<float> & Token::getData() {
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

float &Token::operator[](int idx) {
    return v[idx];
}

float Token::dist(Token &t) {
    float d = 0.0;
    for (int i = 0; i < size(); i++)
        d += (v[i] - t[i]) * (v[i] - t[i]);
    return std::sqrt(d);
}

std::ostream &operator<<(std::ostream &os, Token &t) {
    for (int i = 0; i < t.size(); i++)
        os << t[i] << " ";
    return os;
}
