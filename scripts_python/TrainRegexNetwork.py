import torch
from torch import nn
from torch.utils.data import TensorDataset
from torch.utils.data import DataLoader
from torch import optim
from tqdm import tqdm

from src_python.ModuleRegex import ModuleRegex

from src_python.Dataset import Dataset

if __name__ == "__main__":
    train_file_name = "eng.train"

    # Loading dataset
    train_dataset = Dataset("../datasets/" + train_file_name)
    train_dataset_tokens = torch.load("../datasets/" + train_file_name + "_tokens_regex.pt").float()

    # Extracting target values
    train_tar = torch.tensor([0 if x == 'I-PER' else 1 for x in train_dataset.true_labels])

    # Generating dataset and data loader
    train_ds = TensorDataset(train_dataset_tokens, train_tar)
    train_dl = DataLoader(train_ds, batch_size=128)

    # Generating model
    model = ModuleRegex(train_dataset_tokens.shape[1])

    # Optimizer
    loss_func = nn.CrossEntropyLoss(weight=torch.tensor([5, 1]).float())
    opt = optim.SGD(model.parameters(), lr=0.01)

    epochs = 10

    for epoch in tqdm(range(epochs), desc="Training progress: "):
        model.train()
        for xb, yb in train_dl:
            pred = model(xb)
            loss = loss_func(pred, yb)

            loss.backward()
            opt.step()
            opt.zero_grad()

    torch.save(model.state_dict(), "../models/regex_model.pt")



