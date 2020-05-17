//
// Created by igor on 17/05/2020.
//

#include <iostream>
#include "KnnClassifier.h"
#include "LinearRegression.h"
#include "LogisticRegression.h"
#include "OVRClassifier.h"
#include "RandomClassifier.h"
#include "Analyzer.h"

int main(int argc, char **argv) {
    if (argc != 5) {
        std::cout << "Correct usage: ./Custom_Analyzer <classifier> <type> <trainDataset> <testDataset>" << std::endl;
        std::cout << "<classifier>: knnTree | knnHeap | linearRegression | logisticRegression | ovrLinear | ovrLogistic | random"
                  << std::endl;
        std::cout << "<type>: binary | ner" << std::endl;
        exit(1);
    }

    time_t t1, t2;

    ClassificationType type;
    if (std::string(argv[2]) == "binary")
        type = BINARY;
    else if (std::string(argv[2]) == "ner")
        type = NER;
    else throw std::invalid_argument("Invalid dataset type");

    time(&t1);
    Dataset train(argv[3], type);
    Dataset test(argv[4], type);
    time(&t2);
    std::cout << "Duration of file read: " << t2 - t1 << "s\n";

    Classifier *classifier;
    time(&t1);
    auto classifierName = std::string(argv[1];
    if (classifierName == "knnTree")
        classifier = new KnnClassifier(train, 5);
    else if (classifierName == "knnHeap")
        classifier = new KnnClassifier(train, 5, false);
    else if (classifierName == "linearRegression")
        classifier = new LinearRegression(train);
    else if (classifierName == "logisticRegression")
        classifier = new LogisticRegression(train);
    else if (classifierName == "ovrLinear")
        classifier = new OVRClassifier(train, LINEAR_REGRESSION);
    else if (classifierName == "ovrLogistic")
        classifier = new OVRClassifier(train, LOGISTIC_REGRESSION);
    else if (classifierName == "random")
        classifier = new RandomClassifier(train);
    else throw std::invalid_argument("Invalid classifier type");
    time(&t2);
    std::cout << "Time for the train step: " << t2 - t1 << "s\n";

    time(&t1);
    Analyzer analyzer(*classifier);
    analyzer.analyze(test);
    analyzer.printAnalysis();
    time(&t2);
    std::cout << "Time for the analysis step: " << t2 - t1 << "s\n";

    delete classifier;
    return 0;
}