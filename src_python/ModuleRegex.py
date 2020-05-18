from torch import nn
import torch.nn.functional as F


class Module(nn.Module):
    def __init__(self, input_size):
        super().__init__()
        self.inp = nn.Linear(input_size, 10)
        self.hidden = nn.Linear(10, 5)
        self.out = nn.Linear(5, 2)

    def forward(self, x):
        x = self.inp(x)
        x = F.relu(x)
        x = self.hidden(x)
        x = F.relu(x)
        x = self.out(x)
        return x
