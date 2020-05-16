//
// Created by igor on 15/05/2020.
//

#include <fstream>
#include <string>
#include <sstream>
#include "Dataset.h"

Dataset::Dataset(const std::string &dataFile, const std::string &labelFile, ClassificationType type) : type(type) {
    std::ifstream data(dataFile);
    if (data.fail())
        throw std::invalid_argument("Dataset file " + dataFile + " not found.");
    std::ifstream label(labelFile);
    if (label.fail())
        throw std::invalid_argument("Dataset file " + labelFile + " not found.");

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
