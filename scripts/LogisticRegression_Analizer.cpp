//
// Created by Aloysio Galvão Lopes on 2020-05-16.
//

#include "LogisticRegression.h"
#include "Analyzer.h"
#include <iostream>

int main(){
    // Reading files
    time_t t1, t2;
    time(&t1);
    Dataset train("../data/representation.train.csv", "../data/true_labels.train.csv", BINARY);
    Dataset test("../data/representation.testa.csv", "../data/true_labels.testa.csv", BINARY);
    time(&t2);
    std::cout << "Duration of file read: " << t2-t1 << "s\n";

    time(&t1);
    LogisticRegression regression(train);
    time(&t2);
    std::cout << "Time for the training step: " << t2-t1 << "s\n";

    time(&t1);
    Analyzer analyzer(regression);
    analyzer.analyze(test);
    analyzer.printAnalysis();
    time(&t2);
    std::cout << "Time for the analysis step: " << t2-t1 << "s\n";

}