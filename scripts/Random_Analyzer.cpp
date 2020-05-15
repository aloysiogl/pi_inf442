//
// Created by igor on 15/05/2020.
//

#include <iostream>
#include "RandomClassificator.h"
#include "Analyzer.h"

int main() {
    Dataset train("../data/representation.train.csv", "../data/true_labels.train.csv");
    Dataset test("../data/representation.testa.csv", "../data/true_labels.testa.csv");
    RandomClassificator classificator(train);
    Analyzer analyzer(classificator);
    analyzer.analyze(test);
    analyzer.printAnalysis();
    return 0;
}
