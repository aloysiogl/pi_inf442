//
// Created by Aloysio Galvão Lopes on 2020-05-16.
//

#include "OVRClassifier.h"
#include "LinearRegression.h"
#include "LogisticRegression.h"

OVRClassifier::OVRClassifier(Dataset &dataset, BaseClassifier classifier) : Classifier(dataset) {
    this->baseClassifier = classifier;

    // Creating binary vector of classes, for each of the classes
    for (int c = 0; c < N_CLASSES; c++) {
        std::vector<Class> classes(dataset.size());
        for (int i = 0; i < dataset.size(); ++i) {
            if (dataset[i].getClass() == c)
                classes[i] = (Class) 0;
            else classes[i] = (Class) 1;
        }
        if (baseClassifier == LINEAR_REGRESSION)
            classifiers.push_back(new LinearRegression(dataset, classes));
        else classifiers.push_back(new LogisticRegression(dataset, classes));
    }
}

OVRClassifier::~OVRClassifier() {
    for (int i = 0; i < classifiers.size(); i++)
        delete classifiers[i];
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
