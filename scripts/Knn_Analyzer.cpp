//
// Created by igor on 15/05/2020.
//

#include <iostream>
#include "KnnClassifier.h"
#include "Analyzer.h"

int main() {
    ClassificationType type = BINARY;

    time_t t1, t2;
    time(&t1);
    Dataset train("train-sample", type);
    Dataset test("testa-sample", type);
    time(&t2);
    std::cout << "Duration of file read: " << t2-t1 << "s\n";

    time(&t1);
    KnnClassifier classifier(train, 5);
    time(&t2);
    std::cout << "Time for the building step: " << t2-t1 << "s\n";

    time(&t1);
    Analyzer analyzer(classifier);
    analyzer.analyze(test);
    analyzer.printAnalysis();
    time(&t2);
    std::cout << "Time for the analysis step: " << t2-t1 << "s\n";
    return 0;
}