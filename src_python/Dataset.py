import numpy as np


class Dataset:
    def __init__(self, dataset_location, formatted=False, labels_location=None):
        if formatted:
            if labels_location is None:
                raise Exception("Labels argument not inserted")
            self.data = np.load(dataset_location)
            self.true_labels = np.load(labels_location)


if __name__ == "__main__":
    # TODO remove this test
    train = Dataset("../data/representation.train.npy", True, "../data/true_labels.train.npy")
    # testa = Dataset("../data/representation.testa.npy", True)
    # testb = Dataset("../data/representation.testb.npy", True)
    # print(train.data)
