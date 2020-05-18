from src_python.Dataset import Dataset
import re, torch


class RegexTokenizer:
    def __init__(self, dataset, rules):
        self.dataset = dataset
        self.token_len = len(rules)
        self.rules = rules
        self.check_string = self.get_dataset_string()
        self.index_dict = {}
        for i in range(len(dataset.data)):
            key = dataset.data[i]
            if key in self.index_dict:
                self.index_dict[key] += [i]
            else:
                self.index_dict[key] = [i]
        self.tokens = torch.zeros([len(self.dataset.data), self.token_len], dtype=torch.int32)
        self.set_tokens()

    def get_tokens(self):
        return self.tokens

    def set_tokens(self):
        for i in range(len(self.rules)):
            self.check_rule(rule=self.rules[i], rule_index=i)

    def check_rule(self, rule, rule_index):
        p = re.compile(rule)
        iterator = p.finditer(self.check_string)
        for match in iterator:
            span = match.span()
            hole_pattern = self.check_string[span[0]:span[1]]
            sub_span = re.search('\\b.+\\b', hole_pattern).span()
            sub_string = hole_pattern[sub_span[0]: sub_span[1]]
            if sub_string not in self.index_dict:
                continue
            tokens_to_edit = self.index_dict[sub_string]
            for token in tokens_to_edit:
                self.tokens[token][rule_index] = 1

    def get_dataset_string(self):
        res = ""
        for s in self.dataset.data:
            res += s + "\n"
        return res


if __name__ == "__main__":
    train = Dataset("../datasets/eng.train")

    rules = ['\\b([A-Z])([a-z])+\\b.([A-Z])([a-z])+\\b',
             '\\b([A-Z])([a-z])+\\b']
    tokenizer = RegexTokenizer(dataset=train, rules=rules)
    tokens = tokenizer.get_tokens()