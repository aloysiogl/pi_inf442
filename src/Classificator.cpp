//
// Created by igor on 15/05/2020.
//

#include "Classificator.h"

Classificator::Classificator(Dataset &trainDataset) : dataset(trainDataset) {}

std::vector<Class> Classificator::classify(Dataset &testDataset) {
    std::vector<Class> classes;
    classes.reserve(testDataset.getTokens().size());
    for (auto &t : testDataset.getTokens())
        classes.push_back(classify(t));
    return classes;
}
