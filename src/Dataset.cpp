//
// Created by igor on 15/05/2020.
//

#include <complex>
#include <string>
#include <sstream>
#include "Dataset.h"
#include "cnpy/cnpy.h"

Dataset::Dataset(const std::string &name, ClassificationType type) : type(type) {
    loadNpy(name);
}

std::vector<Token> &Dataset::getTokens() {
    return tokens;
}

int Dataset::size() const {
    return tokens.size();
}

int Dataset::dimension() const {
    if (!tokens.empty())
        return tokens[0].size();
    else return 0;
}

ClassificationType Dataset::getType() const {
    return type;
}

Token &Dataset::operator[](int idx) {
    return tokens[idx];
}

void Dataset::loadNpy(const std::string &name) {
    const int dsize = 1024;
    const int lsize = 24;

    std::string path("../data/representation." + name + ".npy");
    cnpy::NpyArray dataArr = cnpy::npy_load(path);
    auto *data = dataArr.data<double>();

    path = "../data/true_labels." + name + ".npy";
    cnpy::NpyArray labelArr = cnpy::npy_load(path);
    auto labels = *labelArr.data_holder;

    assert(dataArr.shape[0] == labelArr.shape[0]);
    int n = dataArr.shape[0];

    tokens.reserve(n);

    for (int i = 0; i < n; i++) {
        std::vector<double> v(dsize);
        for (int j = 0; j < dsize; j++)
            v[j] = data[dsize * i + j];

        std::string className;
        for (int j = 0; j < lsize; j++)
            if (labels[i * lsize + j] != '\0')
                className.push_back(labels[i * lsize + j]);

        Class c = O;
        if (className == "O")
            c = O;
        else if (className == "I-MISC" || className == "B-MISC")
            c = MISC;
        else if (className == "I-PER" || className == "B-PER")
            c = PER;
        else if (className == "I-LOC" || className == "B-LOC")
            c = LOC;
        else if (className == "I-ORG" || className == "B-ORG")
            c = ORG;
        else
            throw std::invalid_argument("Label type " + className + " not recognized in line " +
                                        std::to_string(tokens.size()));

        tokens.emplace_back(Token(v, c));
    }
}

void Dataset::loadCsv(const std::string &dataName) {
    std::string path("../data/");
    std::ifstream data(path + "representation." + dataName + ".csv");
    std::ifstream label(path + "true_labels." + dataName + ".csv");
    if (data.fail())
        throw std::invalid_argument("Dataset file " + dataName + " not found.");

    if (label.fail())
        throw std::invalid_argument("Label file " + dataName + " not found.");

    std::vector<double> row;
    Class c;
    std::string lineData, lineLabel;

    while (getline(data, lineData) && getline(label, lineLabel)) {
        row.clear();
        std::stringstream s(lineData);

        std::string word;
        while (getline(s, word, ',')) {
            double val = std::strtod(word.c_str(), nullptr);
            row.push_back(val);
        }

        if (lineLabel == "O")
            c = O;
        else if (lineLabel == "I-MISC" || lineLabel == "B-MISC")
            c = MISC;
        else if (lineLabel == "I-PER" || lineLabel == "B-PER")
            c = PER;
        else if (lineLabel == "I-LOC" || lineLabel == "B-LOC")
            c = LOC;
        else if (lineLabel == "I-ORG" || lineLabel == "B-ORG")
            c = ORG;
        else
            throw std::invalid_argument("Label type " + lineLabel + " not recognized in line " +
                                        std::to_string(tokens.size()));

        if (type == BINARY && (c == MISC || c == LOC || c == ORG))
            c = O;

        if (!tokens.empty() && tokens[0].size() != row.size())
            throw std::invalid_argument("Row " + std::to_string(tokens.size()) + " in dataset has inconsistent size");
        tokens.emplace_back(Token(row, c));
    }

    data.close();
    label.close();
}

Dataset Dataset::getBinary(Class c) {
    Dataset newDataset = *this;
    newDataset.setType(BINARY);
    for (int i = 0; i < size(); ++i){
        if ((Class)(*this)[i].getClass() == c)
            newDataset[i].setClass((Class) 0);
        else newDataset[i].setClass((Class) 1);
    }

    return newDataset;
}

void Dataset::setType(ClassificationType type) {
    this->type = type;
}
