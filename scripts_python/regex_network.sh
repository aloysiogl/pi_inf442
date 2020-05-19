#!/usr/bin/env bash

python3 GenerateRegexTokens.py
python3 TrainRegexNetwork.py
python3 VerifyRegexNetwork.py