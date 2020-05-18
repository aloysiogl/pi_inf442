//
// Created by igor on 16/05/2020.
//

#include "KnnKEstimator.h"
#include "KnnClassifier.h"
#include "Analyzer.h"

KnnKEstimator::KnnKEstimator(Dataset &trainDataset, int maxK) : dataset(trainDataset), maxK(maxK) {}

std::vector<std::pair<int, int> > KnnKEstimator::rocCurve(Dataset &testDataset) {
    std::vector<std::pair<int, int>> v;
    std::cout << 0 << " " << 0 << std::endl;
    for (int k = 1; k <= maxK; k++) {
        KnnClassifier classifier(dataset, k);
        Analyzer analyzer(classifier);
        analyzer.analyze(testDataset);
        std::cout << analyzer.falseAlarmRate() << " " << analyzer.sensitivity() << std::endl;
    }
    std::cout << 1 << " " << 1 << std::endl;
    return v;
}
