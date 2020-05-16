//
// Created by Aloysio Galvão Lopes on 2020-05-16.
//

#include <ctime>
#include <iostream>
#include "LinearRegression.h"
#include "Analyzer.h"

int main(){
    // Reading files
    time_t t1, t2;
    time(&t1);
    Dataset train("train-sample", BINARY);
    Dataset test("testa-sample", BINARY);
    time(&t2);
    std::cout << "Duration of file read: " << t2-t1 << "s\n";



    time(&t1);
    LinearRegression regression(train);
    time(&t2);
    std::cout << "Time for the training step: " << t2-t1 << "s\n";

    time(&t1);
    Analyzer analyzer(regression);
    analyzer.analyze(test);
    analyzer.printAnalysis();
    time(&t2);
    std::cout << "Time for the analysis step: " << t2-t1 << "s\n";

}