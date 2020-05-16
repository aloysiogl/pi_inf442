//
// Created by igor on 15/05/2020.
//

#ifndef PI_INF442_CLASS_H
#define PI_INF442_CLASS_H

#include <string>

enum Class {
    PER = 0,
    O = 1,
    MISC = 2,
    LOC = 3,
    ORG = 4,
    UNDEFINED = 5,
    N_CLASSES = 5
};

std::string to_string(Class c);

#endif //PI_INF442_CLASS_H
