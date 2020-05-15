//
// Created by igor on 15/05/2020.
//

#include "Token.h"

Token::Token() {
    c = UNDEFINED;
}

Token::Token(std::vector<double> &v, Class c) {
    this->v = v;
    this->c = c;
}

void Token::setClass(Class c) {
    this->c = c;
}

Class Token::getClass() {
    return c;
}

int Token::getSize() const {
    return v.size();
}