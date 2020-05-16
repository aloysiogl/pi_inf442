//
// Created by igor on 15/05/2020.
//

#include "Classifier.h"

Classifier::Classifier(Dataset &trainDataset) : dataset(trainDataset), type(dataset.getType()) {}

std::vector<Class> Classifier::classify(Dataset &testDataset) {
    std::vector<Class> classes;
    classes.reserve(testDataset.getTokens().size());
    for (auto &t : testDataset.getTokens())
        classes.push_back(classify(t));
    return classes;
}

ClassificationType Classifier::getType() {
    return type;
}

double Classifier::classificationProbability(Class c, Token &token) {
    throw "Probability for classification not implemented on this classifier";
}
