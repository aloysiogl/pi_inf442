#!/usr/bin/env bash

python3 GenerateRegexTokens.py eng.train eng.testa
python3 TrainRegexNetwork.py eng.train
python3 VerifyRegexNetwork.py eng.testa