from sklearn.linear_model import LogisticRegressionCV
from src_python.Dataset import Dataset
import numpy as np

if __name__ == "__main__":
    train = Dataset("../data/representation.train.npy", True, "../data/true_labels.train.npy")
    testa = Dataset("../data/representation.train.npy", True, "../data/true_labels.testa.npy")

    # # Data normalization
    # row_sums = train.data.sum(axis=1)
    # train.data = train.data / row_sums[:, np.newaxis]
    # row_sums = testa.data.sum(axis=1)
    # testa.data = testa.data / row_sums[:, np.newaxis]

    labels = [1 if x == 'I-PER' else 0 for x in train.true_labels]

    test_labels = [1 if x == 'I-PER' else 0 for x in testa.true_labels]

    print("Running training...")

    classif = LogisticRegressionCV(multi_class='ovr', verbose=1).fit(train.data, labels)

    print("Running prediction...")
    pred = classif.predict(testa.data)

    print("Calculating differences...")
    tot = 0
    for i in range(len(test_labels)):
        if pred[i] == test_labels[i]:
            pass
        else:
            tot += 1
    print("Total differences: ", tot, " total size: ", len(test_labels))

