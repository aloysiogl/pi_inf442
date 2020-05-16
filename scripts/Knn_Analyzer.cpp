//
// Created by igor on 15/05/2020.
//

#include <iostream>
#include "KnnClassifier.h"
#include "Analyzer.h"

int main() {
    ClassificationType type = BINARY;
    Dataset train("train-sample", type);
    Dataset test("testa-sample", type);
    KnnClassifier classifier(train, 5);
    Analyzer analyzer(classifier);
    analyzer.analyze(test);
    analyzer.printAnalysis();
    return 0;
}