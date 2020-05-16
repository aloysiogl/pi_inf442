//
// Created by Aloysio Galvão Lopes on 2020-05-16.
//

#include <ctime>
#include <iostream>
#include "OVRClassifier.h"
#include "Analyzer.h"

int main(){
    // Reading files
    time_t t1, t2;
    time(&t1);
    Dataset train("../data/representation.train.csv", "../data/true_labels.train.csv", NER);
    Dataset test("../data/representation.testa.csv", "../data/true_labels.testa.csv", NER);
    time(&t2);
    std::cout << "Duration of file read: " << t2-t1 << "s\n";



    time(&t1);
    OVRClassifier classifier(train, LOGISTIC_REGRESSION);
    time(&t2);
    std::cout << "Time for the training step: " << t2-t1 << "s\n";

    time(&t1);
    Analyzer analyzer(classifier);
    analyzer.analyze(test);
    analyzer.printAnalysis();
    time(&t2);
    std::cout << "Time for the analysis step: " << t2-t1 << "s\n";

}
