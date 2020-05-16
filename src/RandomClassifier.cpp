//
// Created by igor on 15/05/2020.
//

#include <chrono>
#include "RandomClassifier.h"

RandomClassifier::RandomClassifier(Dataset &trainDataset) :
        Classifier(trainDataset), distribution(0, N_CLASSES - 1),
        state(std::chrono::system_clock::now().time_since_epoch().count()) {
    if (type == BINARY)
        distribution = std::uniform_int_distribution<int>(0, 1);
}

Class RandomClassifier::classify(Token &token) {
    return (Class) distribution(state);
}
