//
// Created by igor on 15/05/2020.
//

#ifndef PI_INF442_CLASSIFIER_H
#define PI_INF442_CLASSIFIER_H

#include "Class.h"
#include "Dataset.h"

class Classifier {
public:
    explicit Classifier(Dataset &trainDataset);

    virtual ~Classifier();

    virtual Class classify(Token &token) = 0;

    virtual std::vector<Class> classify(Dataset &testDataset);

    virtual float classificationProbability(Class c, Token &token);

    ClassificationType getType();

protected:
    Dataset &dataset;
    ClassificationType type;
};


#endif //PI_INF442_CLASSIFIER_H
