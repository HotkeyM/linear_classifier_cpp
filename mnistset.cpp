#include "mnistset.h"


MnistSet::MnistSet()
{

}

int MnistSet::ReverseInt(int i)
{
    unsigned char c1, c2, c3, c4;

    c1 = i & 255;
    c2 = (i >> 8) & 255;
    c3 = (i >> 16) & 255;
    c4 = (i >> 24) & 255;

    return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}

void MnistSet::LoadFile(const std::string images, const std::string labels)
{
    std::ifstream input( images, std::ios::binary );
    int magic;

    input.read((char*)&magic,4);
    magic = ReverseInt(magic);
    if (magic != 0x803) throw std::invalid_argument("File is not MNIST file.");

    input.read((char*)&n_samples,4);
    n_samples = ReverseInt(n_samples);

    input.read((char*)&cols,4);
    cols = ReverseInt(cols);

    input.read((char*)&rows,4);
    rows = ReverseInt(rows);



    for (int i = 0; i < n_samples; i++)
    {
        std::vector<float> v(cols*rows);
        for (int j = 0; j < cols*rows; j++)
        {
            unsigned char value;
            input.read((char *)&value,1);
            v[j] = (float) value;

        }
        samples.push_back(v);
    }


    std::ifstream input_labels( labels, std::ios::binary );


    input_labels.read((char*)&magic,4);
    magic = ReverseInt(magic);
    if (magic != 0x801) throw std::invalid_argument("File is not MNIST labels file.");

    int labels_n_samples;
    input_labels.read((char*)&labels_n_samples,4);
    labels_n_samples = ReverseInt(labels_n_samples);

    if (labels_n_samples != n_samples) throw std::length_error("MNIST and MNIST labels files have different length.");

    for (int i = 0; i < n_samples; i++)
    {
        std::vector<int> v(10,0);
        unsigned char value;
        input_labels.read((char *)&value,1);
        v.at(value) = 1;
        this->labels.push_back(v);
    }



    return;

    //intput >> this->n_samples;
    //intput >>
    //for
}
