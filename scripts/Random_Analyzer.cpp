//
// Created by igor on 15/05/2020.
//

#include <iostream>
#include "RandomClassifier.h"
#include "Analyzer.h"

int main() {
    ClassificationType type = BINARY;
    Dataset train("../data/representation.train.csv", "../data/true_labels.train.csv", type);
    Dataset test("../data/representation.testa.csv", "../data/true_labels.testa.csv", type);
    RandomClassifier classifier(train);
    Analyzer analyzer(classifier);
    analyzer.analyze(test);
    analyzer.printAnalysis();
    return 0;
}
