import numpy as np
import sklearn as sk
import sklearn.linear_model
from sklearn import preprocessing
import torch
from torch import nn
import torch.nn.functional as F
from torch.utils.data import TensorDataset
from torch.utils.data import DataLoader
from torch import optim
import os

from src_python.Dataset import Dataset

if __name__ == "__main__":
    # Loading datasets
    train_dataset = Dataset("../datasets/eng.train")
    train_dataset_tokens = torch.load("../src_python/tokens_train.pt").float()

    train_tar = torch.tensor([0 if x == 'I-PER' else 1 for x in train_dataset.true_labels])

    train_ds = TensorDataset(train_dataset_tokens, train_tar)
    train_dl = DataLoader(train_ds, batch_size=128)

    model = Module()

    loss_func = nn.CrossEntropyLoss(weight=torch.tensor([7, 1]).float())
    opt = optim.SGD(model.parameters(), lr=0.01)

    epochs = 1

    for epoch in range(epochs):
        model.train()
        for xb, yb in train_dl:
            pred = model(xb)
            loss = loss_func(pred, yb)

            loss.backward()
            opt.step()
            opt.zero_grad()

        # model.eval()
        # with torch.no_grad():
        #     valid_loss = sum(loss_func(model(xb), yb) for xb, yb in valid_dl)

        print(epoch)

    torch.save(model, "model.pt")
    # print(iter(train_dl).next()[0].shape)

    test_dataset = Dataset("../datasets/eng.testa")
    test_dataset_tokens = torch.load("../src_python/tokens_test.pt").float()

    test_tar = torch.tensor([0 if x == 'I-PER' else 1 for x in test_dataset.true_labels])

    # for i in test_tar:
    #     if i == 1:
    #         print("here")

    test_ds = TensorDataset(test_dataset_tokens, test_tar)

    # model = torch.load("model.pt")

    model.eval()
    with torch.no_grad():
        # print(train_dataset_tokens)
        pred = torch.argmax(model(test_dataset_tokens), dim=1)
        # print(model(test_dataset_tokens))
        # print(sklearn.metrics.precision_score(pred.detach().numpy(), test_tar.detach().numpy()))
        cf = sklearn.metrics.confusion_matrix(test_tar.detach().numpy(), pred.detach().numpy())
        print(cf)
        print((cf[0,0]+cf[1,1])/np.sum(cf))
        print(cf[0,0]/(cf[0,0]+cf[1,0]))



