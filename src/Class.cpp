//
// Created by igor on 15/05/2020.
//

#include <iostream>
#include "Class.h"

std::string to_string(Class c) {
    switch(c) {
        case PER:
            return "PER";
        case O:
            return "O";
        case MISC:
            return "MISC";
        case LOC:
            return "LOC";
        case ORG:
            return "ORG";
        case UNDEFINED:
            return "UNDEFINED";
    }
    throw std::invalid_argument("Class is not valid");
}
