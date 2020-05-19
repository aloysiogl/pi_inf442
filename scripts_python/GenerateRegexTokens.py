import sys, os
from pathlib import Path
currentDirectory = os.getcwd()
path = Path(currentDirectory)
sys.path.insert(0, str(path.parent))
os.environ['KMP_DUPLICATE_LIB_OK']='True'

from src_python.RegexTokenizer import RegexTokenizer
from src_python.Dataset import Dataset
import torch

if __name__ == "__main__":
    train_file_name = "eng.train"
    test_file_name = "eng.testa"

    # Load datasets
    train_dataset = Dataset("../datasets/"+train_file_name)
    test_dataset = Dataset("../datasets/"+test_file_name)

    rules = ['\\b([A-Z])([a-z])+\\b.([A-Z])([a-z])+\\b',
             '\\b([A-Z])([a-z])+\\b',
             '\\b([A-Z])+([a-z])+\\b',
             '\\b([A-Z])([a-z]){3}\\b',
             '\\b([A-Z])([a-z]){4}\\b',
             '\\b([A-Z])([a-z]){5}\\b',
             '\\b([A-Z])([a-z]){6}\\b',
             '\\b([A-Z])([a-z]){7}\\b'
             '\\b([A-Z])([a-z]){3,7}\\b',
             '\\b([A-Z])([a-z]){0,2}\\b',
             '\\b([A-Z])([a-z]){8,12}\\b',
             '\\b([A-Z])([a-z]){13,20}\\b']

    # Getting tokenizers
    train_tokenizer = RegexTokenizer(train_dataset, rules)
    test_tokenizer = RegexTokenizer(test_dataset, rules)

    # Generating output files
    train_tokens = train_tokenizer.get_tokens()
    test_tokens = test_tokenizer.get_tokens()

    torch.save(train_tokens, "../datasets/"+train_file_name+"_tokens_regex.pt")
    torch.save(test_tokens, "../datasets/"+test_file_name+"_tokens_regex.pt")

