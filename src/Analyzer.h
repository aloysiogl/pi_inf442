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

    double overall(Class c = PER);

    double precision(Class c = PER);

    double negativePredictedValue(Class c = PER);

    double sensitivity(Class c = PER);

    double specificity(Class c = PER);

    double fScore(Class c = PER);

private:
    Classifier &classifier;
    std::vector<std::vector<int>> confusionMatrix;
    int nClasses;
};


#endif //PI_INF442_ANALYZER_H
