import sys, os
from pathlib import Path
currentDirectory = os.getcwd()
path = Path(currentDirectory)
sys.path.insert(0, str(path.parent))
os.environ['KMP_DUPLICATE_LIB_OK']='True'

import sklearn.linear_model
import torch

from torch.utils.data import TensorDataset

from src_python.ModuleRegex import ModuleRegex

from src_python.Dataset import Dataset


if __name__ == "__main__":
    test_file_name = "eng.testa"

    # Loading dataset
    test_dataset = Dataset("../datasets/"+test_file_name)
    test_dataset_tokens = torch.load("../datasets/"+test_file_name+"_tokens_regex.pt").float()

    # Extracting target values
    test_tar = torch.tensor([0 if x == 'I-PER' else 1 for x in test_dataset.true_labels])

    # Generating dataset file
    test_ds = TensorDataset(test_dataset_tokens, test_tar)

    model = ModuleRegex(test_dataset_tokens.shape[1])
    model.load_state_dict(torch.load("../models/regex_model.pt"))

    model.eval()
    with torch.no_grad():
        pred = torch.argmax(model(test_dataset_tokens), dim=1)
        print(sklearn.metrics.confusion_matrix(test_tar.detach().numpy(), pred.detach().numpy()))
        print("Dataset size: ", test_tar.shape[0])




