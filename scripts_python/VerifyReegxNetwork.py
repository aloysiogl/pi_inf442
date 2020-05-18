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

#TODO create file
class Module(nn.Module):
    def __init__(self):
        super().__init__()
        self.inp = nn.Linear(2, 200)
        self.out = nn.Linear(200, 2)

    def forward(self, x):
        x = self.inp(x)
        x = F.relu(x)
        x = self.out(x)
        return x


if __name__ == "__main__":
    test_dataset = Dataset("../datasets/eng.testa")
    test_dataset_tokens = torch.load("../src_python/tokens_test.pt").float()

    test_tar = torch.tensor([0 if x == 'I-PER' else 1 for x in test_dataset.true_labels])

    for i in test_tar:
        if i == 1:
            print("here")

    test_ds = TensorDataset(test_dataset_tokens, test_tar)

    model = torch.load("model.pt")

    model.eval()
    with torch.no_grad():
        pred = torch.argmax(model(test_dataset_tokens), dim=1)
        # print(model(test_dataset_tokens))
        # print(sklearn.metrics.precision_score(pred.detach().numpy(), test_tar.detach().numpy()))
        print(sklearn.metrics.confusion_matrix(test_tar.detach().numpy(), pred.detach().numpy()))
    # print(test_dataset_tokens)




