#!/usr/bin/env bash

python3 GenerateRegexTokens.py
python3 TrainRegexNetwork.py eng.testa
python3 VerifyRegexNetwork.py eng.testa