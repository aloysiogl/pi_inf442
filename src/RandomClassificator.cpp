//
// Created by igor on 15/05/2020.
//

#include <chrono>
#include "RandomClassificator.h"

RandomClassificator::RandomClassificator(Dataset &trainDataset) :
        Classificator(trainDataset), distribution(0, N_CLASSES - 1),
        state(std::chrono::system_clock::now().time_since_epoch().count()) {}

Class RandomClassificator::classify(Token &token) {
    return (Class) distribution(state);
}
