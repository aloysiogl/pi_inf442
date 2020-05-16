//
// Created by Aloysio Galvão Lopes on 2020-05-16.
//

#ifndef PI_INF442_OVRCLASSIFIER_H
#define PI_INF442_OVRCLASSIFIER_H

#include "Classifier.h"

enum BaseClassifier {
    LINEAR_REGRESSION = 0,
    LOGISTIC_REGRESSION = 1
};

using std::vector;

class OVRClassifier : public Classifier {
public:
    OVRClassifier(Dataset& dataset, BaseClassifier classifier);
    ~OVRClassifier();

    Class classify(Token& token);

private:
    void train();
    vector<Dataset> datasets;
    vector<Classifier*> classifiers;
    BaseClassifier baseClassifier;
};


#endif //PI_INF442_OVRCLASSIFIER_H
