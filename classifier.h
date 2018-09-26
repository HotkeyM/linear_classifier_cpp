#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include "mnistset.h"
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <iostream>

template <class T, class U>
float CrossProduct(const std::vector<T> &one, const std::vector<U> &two)
{

    float result = 0.0f;

    if (one.size() != two.size()) throw std::length_error("Cross product arguments do not match.");

    auto it1 = one.begin();
    auto it2 = two.begin();

    while (it1 != one.end())
    {
        result += (*it1) * (*it2);
        it1++;
        it2++;

    }

    return result;

}

class Classifier
{
private:

    int CountErrors(const MnistSet &set) const;

    std::vector<std::vector<float>> thetas;

    int n_features;

    void InitRandomThetas();

public:
    void Train(const MnistSet &set, int epochs = 3);

    Classifier();

};

#endif // CLASSIFIER_H
