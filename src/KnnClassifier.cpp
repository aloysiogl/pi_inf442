//
// Created by igor on 16/05/2020.
//

#include "KnnClassifier.h"

KnnClassifier::KnnClassifier(Dataset &trainDataset, int k) : Classifier(trainDataset), k(k) {
    int n = dataset.size();
    int d = dataset.dimension();
    auto array = annAllocPts(n, d);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < d; j++)
            array[i][j] = dataset[i][j];

    tree = new ANNkd_tree(array, n, d);
}

KnnClassifier::~KnnClassifier() {
    delete tree;
}

Class KnnClassifier::classify(Token &token) {
    auto *idxArray = new ANNidx[k];
    auto *distArray = new ANNdist[k];
    tree->annkSearch(token.getData().data(), k, idxArray, distArray);

    std::vector<double> cnt(N_CLASSES, 0);
    std::vector<int> infCnt(N_CLASSES, 0);
    bool hasInf = false;
    for (int i = 0; i < k; i++) {
        if (distArray[i] > DBL_EPSILON)
            cnt[dataset[idxArray[i]].getClass()] += 1 / distArray[i];
        else {
            hasInf = true;
            infCnt[dataset[idxArray[i]].getClass()]++;
        }
    }

    Class maxIdx = PER;
    for (int i = 0; i < N_CLASSES; i++)
        if ((!hasInf && cnt[i] > cnt[maxIdx]) || (hasInf && infCnt[i] > infCnt[maxIdx]))
            maxIdx = (Class) i;

    delete[]idxArray;
    delete[]distArray;

    return maxIdx;
}
