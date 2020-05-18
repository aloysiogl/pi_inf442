//
// Created by igor on 16/05/2020.
//

#include <queue>
#include "KnnClassifier.h"

KnnClassifier::KnnClassifier(Dataset &trainDataset, int k, bool useKdTree) :
        Classifier(trainDataset), k(k) {
    this->useKdTree = useKdTree;
    if (useKdTree) {
        int n = dataset.size();
        int d = dataset.dimension();
        auto array = annAllocPts(n, d);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < d; j++)
                array[i][j] = dataset[i][j];

        tree = new ANNkd_tree(array, n, d);
    }
}

KnnClassifier::~KnnClassifier() {
    if (useKdTree)
        delete tree;
}

Class KnnClassifier::classify(Token &token) {
    std::vector<float> cnt(N_CLASSES, 0);
    std::vector<int> infCnt(N_CLASSES, 0);
    bool hasInf = false;

    if (useKdTree) {
        auto *idxArray = new ANNidx[k];
        auto *distArray = new ANNdist[k];
        auto q = annAllocPt(token.size());
        for (int i = 0; i < token.size(); i++)
            q[i] = token[i];
        tree->annkSearch(q, k, idxArray, distArray);


        for (int i = 0; i < k; i++) {
            if (distArray[i] > DBL_EPSILON)
                cnt[dataset[idxArray[i]].getClass()] += 1 / distArray[i];
            else {
                hasInf = true;
                infCnt[dataset[idxArray[i]].getClass()]++;
            }
        }

        delete[]idxArray;
        delete[]distArray;
    } else {
        auto comp = [&token](Token* t1, Token* t2) { return t1->dist(token) > t2->dist(token); };
        std::priority_queue<Token*, std::vector<Token*>, decltype(comp)> pq(comp);
        for (int i = 0; i < dataset.size(); i++) {
            if ((int) pq.size() < k)
                pq.push(&dataset[i]);
            else {
                if (pq.top()->dist(token) > dataset[i].dist(token)) {
                    pq.pop();
                    pq.push(&dataset[i]);
                }
            }
        }

        for (int i = 0; i < (int) pq.size(); i++) {
            float dist = pq.top()->dist(token);
            if (dist > FLT_EPSILON)
                cnt[pq.top()->getClass()] += 1 / dist;
            else {
                hasInf = true;
                infCnt[pq.top()->getClass()]++;
            }
        }
    }

    Class maxIdx = PER;
    for (int i = 0; i < N_CLASSES; i++)
        if ((!hasInf && cnt[i] > cnt[maxIdx]) || (hasInf && infCnt[i] > infCnt[maxIdx]))
            maxIdx = (Class) i;

    return maxIdx;
}
