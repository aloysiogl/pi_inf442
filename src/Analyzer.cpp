//
// Created by igor on 15/05/2020.
//

#include <iomanip>
#include <iostream>
#include "Analyzer.h"

Analyzer::Analyzer(Classificator &classificator) : classificator(classificator) {
    confusionMatrix.assign(N_CLASSES + 1, std::vector<int>(N_CLASSES + 1, 0));
}

void Analyzer::analyze(Dataset &testDataset) {
    auto classes = classificator.classify(testDataset);

    for (int i = 0; i < testDataset.getSize(); i++) {
        int ci = classes[i];
        int cj = testDataset.getToken(i).getClass();
        confusionMatrix[ci][cj]++;
    }

    // Computing sums
    for (int i = 0; i < N_CLASSES; i++) {
        int s = 0;
        for (int j = 0; j < N_CLASSES; j++)
            s += confusionMatrix[i][j];
        confusionMatrix[i][N_CLASSES] = s;
    }
    for (int j = 0; j < N_CLASSES; j++) {
        int s = 0;
        for (int i = 0; i < N_CLASSES; i++)
            s += confusionMatrix[i][j];
        confusionMatrix[N_CLASSES][j] = s;
    }
    confusionMatrix[N_CLASSES][N_CLASSES] = testDataset.getSize();
}

void Analyzer::printAnalysis() {
    std::cout << "CONFUSION MATRIX: (Predicted \u2192 x Classified \u2193)" << std::endl;
    for (int i = 0; i <= N_CLASSES; i++) {
        for (int j = 0; j <= N_CLASSES; j++)
            std::cout << std::setw(4) << confusionMatrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "OVERALL ACCURACY: " << overallAccuracy() << std::endl;
}

std::vector<std::vector<int>> Analyzer::getConfusionMatrix() {
    return confusionMatrix;
}

double Analyzer::overallAccuracy() {
    int s = 0;
    for (int i = 0; i < N_CLASSES; i++)
        s += confusionMatrix[i][i];
    return (double) s / (double) confusionMatrix[N_CLASSES][N_CLASSES];
}
