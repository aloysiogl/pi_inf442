//
// Created by igor on 15/05/2020.
//

#include <iomanip>
#include <iostream>
#include "Analyzer.h"

Analyzer::Analyzer(Classifier &classifier) : classifier(classifier) {
    if (classifier.getType() == BINARY)
        nClasses = 2;
    else nClasses = N_CLASSES;
    confusionMatrix.assign(nClasses + 1, std::vector<int>(nClasses + 1, 0));
}

void Analyzer::analyze(Dataset &testDataset) {
    auto classes = classifier.classify(testDataset);

    if (classifier.getType() == BINARY) {
        for (int i = 0; i < testDataset.size(); i++) {
            Class cj = classes[i];
            Class ci = testDataset[i].getClass();
            int mi = ci != PER, mj = cj != PER;
            confusionMatrix[mi] [mj]++;
        }
    } else {
        for (int i = 0; i < testDataset.size(); i++) {
            Class cj = classes[i];
            Class ci = testDataset[i].getClass();
            confusionMatrix[ci][cj]++;
        }
    }

    // Computing sums
    for (int i = 0; i < nClasses; i++) {
        int s = 0;
        for (int j = 0; j < nClasses; j++)
            s += confusionMatrix[i][j];
        confusionMatrix[i][nClasses] = s;
    }
    for (int j = 0; j < nClasses; j++) {
        int s = 0;
        for (int i = 0; i < nClasses; i++)
            s += confusionMatrix[i][j];
        confusionMatrix[nClasses][j] = s;
    }
    confusionMatrix[nClasses][nClasses] = testDataset.size();
}

void Analyzer::printAnalysis() {
    std::cout << "CONFUSION MATRIX: (Predicted \u2192 x Actual \u2193)" << std::endl;
    std::cout << std::setw(5) << "";
    for (int j = 0; j < nClasses; j++)
        std::cout << std::setw(4) << to_string((Class) j) << " ";
    std::cout << std::setw(4) << "SUM" << std::endl;
    for (int i = 0; i <= nClasses; i++) {
        if (i != nClasses)
            std::cout << std::setw(4) << to_string((Class) i) << " ";
        else std::cout << std::setw(4) << "SUM" << " ";
        for (int j = 0; j <= nClasses; j++)
            std::cout << std::setw(4) << confusionMatrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "OVERALL ACCURACY: " << overall() << std::endl;
    std::cout << "F SCORE: " << fScore() << std::endl;
}

std::vector<std::vector<int>> Analyzer::getConfusionMatrix() {
    return confusionMatrix;
}

int Analyzer::truePositive(Class c) {
    return confusionMatrix[c][c];
}

int Analyzer::trueNegative(Class c) {
    return confusionMatrix[nClasses][nClasses] - truePositive(c) - falseNegative(c) - falsePositive(c);
}

int Analyzer::falseNegative(Class c) {
    return confusionMatrix[c][nClasses] - confusionMatrix[c][c];
}

int Analyzer::falsePositive(Class c) {
    return confusionMatrix[nClasses][c] - confusionMatrix[c][c];
}

double Analyzer::overall(Class c) {
    return (double) (truePositive(c) + trueNegative(c)) / (double) confusionMatrix[nClasses][nClasses];
}

double Analyzer::precision(Class c) {
    return (double) truePositive(c) / (double) (truePositive(c) + falsePositive(c));
}

double Analyzer::negativePredictedValue(Class c) {
    return (double) trueNegative(c) / (double) (trueNegative(c) + falseNegative(c));
}

double Analyzer::sensitivity(Class c) {
    return (double) truePositive(c) / (double) (truePositive(c) + falseNegative(c));
}

double Analyzer::specificity(Class c) {
    return (double) trueNegative(c) / (double) (trueNegative(c) + falsePositive(c));
}

double Analyzer::fScore(Class c) {
    return 2.0 * precision(c) * sensitivity(c) / (precision(c) + sensitivity(c));
}
