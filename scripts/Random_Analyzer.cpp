//
// Created by igor on 15/05/2020.
//

#include <iostream>
#include "RandomClassifier.h"
#include "Analyzer.h"

int main() {
    ClassificationType type = BINARY;
    Dataset train("train-sample", type);
    Dataset test("testa-sample", type);
    RandomClassifier classifier(train);
    Analyzer analyzer(classifier);
    analyzer.analyze(test);
    analyzer.printAnalysis();
    return 0;
}
