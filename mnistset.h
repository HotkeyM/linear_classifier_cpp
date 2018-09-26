#ifndef MNISTSET_H
#define MNISTSET_H

#include <vector>
#include <string>

#include <stdexcept>

#include <fstream>
#include <iterator>
#include <algorithm>

class MnistSet
{
private:
    std::string filename;


public:
    int n_samples;
    int cols;
    int rows;

    std::vector <std::vector<float>> samples;
    std::vector <std::vector<int>> labels;


    MnistSet();

    static int ReverseInt (int i);

    void LoadFile(const std::string images, const std::string labels);
};

#endif // MNISTSET_H
