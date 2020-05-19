import sys, os
from pathlib import Path
currentDirectory = os.getcwd()
path = Path(currentDirectory)
sys.path.insert(0, str(path.parent))
os.environ['KMP_DUPLICATE_LIB_OK']='True'

import sklearn.linear_model
import torch
import numpy as np

from torch.utils.data import TensorDataset
import sys

from src_python.ModuleRegex import ModuleRegex

from src_python.Dataset import Dataset


if __name__ == "__main__":
    test_file_name = sys.argv[1]

    # Loading dataset
    test_dataset = Dataset("../datasets/"+test_file_name)
    test_dataset_tokens = torch.load("../datasets/"+test_file_name+"_tokens_regex.pt").float()

    # Extracting target values
    test_tar = torch.tensor([0 if x == 'I-PER' or x == 'B-PER' else 1 for x in test_dataset.true_labels])

    # Generating dataset file
    test_ds = TensorDataset(test_dataset_tokens, test_tar)

    model = ModuleRegex(test_dataset_tokens.shape[1])
    model.load_state_dict(torch.load("../models/regex_model.pt"))

    model.eval()
    with torch.no_grad():
        pred = torch.argmax(model(test_dataset_tokens), dim=1)
        test_tar = test_tar.detach().numpy()
        pred = pred.detach().numpy()

        print('Confusion matrix:')
        print(sklearn.metrics.confusion_matrix(test_tar, pred))

        test_tar = np.array(test_tar == 0, dtype=int)
        pred = np.array(pred == 0, dtype=int)
        print('TRUE POSITIVE RATE:', sklearn.metrics.recall_score(test_tar, pred))
        print('F-SCORE:', sklearn.metrics.f1_score(test_tar, pred))
        print("Dataset size: ", test_tar.shape[0])

