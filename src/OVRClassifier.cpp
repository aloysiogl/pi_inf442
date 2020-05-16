//
// Created by Aloysio Galvão Lopes on 2020-05-16.
//

#include "OVRClassifier.h"
#include "LinearRegression.h"

OVRClassifier::OVRClassifier(Dataset &dataset, BaseClassifier classifier) : Classifier(dataset) {
    this->baseClassifier = classifier;
    for (int i = 0; i < N_CLASSES; ++i)
        datasets.push_back(dataset.getBinary((Class) i));
    train();
}

void OVRClassifier::train() {
    if (baseClassifier == LINEAR_REGRESSION){
        for (int i = 0; i < N_CLASSES; ++i)
            classifiers.push_back(new LinearRegression(datasets[i]));
    }
}

Class OVRClassifier::classify(Token &token) {
    int clf = 0;
    float prob = classifiers[0]->classificationProbability((Class) 0, token);
    for (int i = 0; i < N_CLASSES; ++i){
        float newProb = classifiers[i]->classificationProbability((Class) 0, token);
        if (newProb > prob){
            clf = i;
            prob = newProb;
        }
    }
    return (Class) clf;
}
