//
// Created by igor on 15/05/2020.
//

#ifndef PI_INF442_ANALYZER_H
#define PI_INF442_ANALYZER_H

#include "Classifier.h"

class Analyzer {
public:
    explicit Analyzer(Classifier &classifier);

    void analyze(Dataset &testDataset);

    void printAnalysis();

    std::vector<std::vector<int>> getConfusionMatrix();


    int truePositive(Class c = PER);

    int trueNegative(Class c = PER);

    int falseNegative(Class c = PER);

    int falsePositive(Class c = PER);

    float overall(Class c = PER);

    float precision(Class c = PER);

    float negativePredictedValue(Class c = PER);

    float sensitivity(Class c = PER);

    float specificity(Class c = PER);

    float falseAlarmRate(Class c = PER);

    float fScore(Class c = PER);

private:
    Classifier &classifier;
    std::vector<std::vector<int>> confusionMatrix;
    int nClasses;
};


#endif //PI_INF442_ANALYZER_H
