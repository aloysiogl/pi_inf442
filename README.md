# Computer science project (PI) : Data anonymization

## Task

You are a Data Scientist in an industry that deals with private data. Suppose
you have transcripts from interactions people had with their Google Home product.
Your team wants to do some fancy machine learning to predict your users'
behaviour, e.g. what they are going to buy next. The problem is your data
comes from many countries, which don't have the same legislation regarding
private data, and this data comes from subsidiaries so your users did not agree
to pass their data on to the holding company. Your mission, should you choose
to accept it, is to anonymize all these texts to remove any personal data before
handing them out to the rest of the team.

## Code structure

We have implemented 6 methods to classify the tokens from the BERT prerocessing. 
- In C++: Knn, Linear Regression, Logistic Regression, OneVsRest adaptations for 
the linear and logistic regressions.
- In Python: Neural network

We have also implemented a method that takes regex expressions outputs and feeds
them into another neural network, in Python

#### C++ 

The directory `src` contains the source code with all the classifiers, and auxiliar
classes like Token, Dataset and Analyzer. `scripts` contains the executables for the
validation of the methods. `third_party` contains external libraries we used in the code.

#### Python

The directory `src_python` contains code used for the regex classifier method.
`scripts_python` contains scripts to run this method and other auxiliary work.
`models` will contain some saved networks for the datasets.
`kaggle_notebook` contains some notebooks that were used in kaggle to parse datasets
and for the neural network that receives BERT tokens as inputs.

#### Datasets

We placed all raw datasets in `datasets`, and a `data` directory must be downloaded
from <https://www.enseignement.polytechnique.fr/informatique/INF442/PI/data.zip>,
unzipped and placed here for the code to work. 

## Instructions to run the project

Essential libraries: cmake, eigen, zlib and unzip.

```
sudo apt update
sudo apt install build-essential cmake libeigen3-dev zlib1g-dev unzip
```

Downloading data folder:

```
wget "https://www.enseignement.polytechnique.fr/informatique/INF442/PI/data.zip"
unzip data.zip
rm data.zip
rm -r __MACOSX
```

Compiling everything:

```
mkdir build
cd build
cmake ..
make
```

This creates a `bin` directory with all the executables of the project.
All analyzers, except Custom_Analyzer are configured to run on CONLL2003
english dataset with test a. 

Look at datasets/aws.sh if you want more datasets to play with, and look
at datasets/results.txt if you wish to view the results we obtained directly.
