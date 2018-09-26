#include <iostream>
#include <vector>
#include "mnistset.h"
#include"classifier.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello Mnist!" << endl;

    try
    {

    MnistSet s;
    s.LoadFile("t10k-images.idx3-ubyte", "t10k-labels.idx1-ubyte");

    Classifier c;
    c.Train(s,10);
    }
    catch(const std::exception& e)
    {
        std::cout << "Unpredicted exception: " << e.what() << "\n";
}
    return 0;
}
