//
// Created by igor on 15/05/2020.
//

#ifndef PI_INF442_ANALYZER_H
#define PI_INF442_ANALYZER_H

#include "Classificator.h"

class Analyzer {
public:
    explicit Analyzer(Classificator &classificator);

    void analyze(Dataset &testDataset);

    void printAnalysis();

    std::vector<std::vector<int>> getConfusionMatrix();

    double overallAccuracy();

    // TODO: Calculate other metrics

private:
    Classificator &classificator;
    std::vector<std::vector<int>> confusionMatrix;
};


#endif //PI_INF442_ANALYZER_H
