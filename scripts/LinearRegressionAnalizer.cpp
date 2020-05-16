//
// Created by Aloysio Galvão Lopes on 2020-05-16.
//

#include <ctime>
#include <iostream>
#include "Dataset.h"

int main(){
    // Reading files
    time_t t1, t2;
    time(&t1);
    Dataset train("train-sample");
    Dataset test("testa-sample");
    time(&t2);
    std::cout << "Duration of file read: " << t2-t1 << "s\n";



}