#include "classifier.h"

void Classifier::InitRandomThetas()
{
    for (auto &v: thetas)
    {
        for (float &theta: v)
        {
            theta = (float)rand()/(float)(RAND_MAX/1.0f);
        }
    }
}

void Classifier::Train(const MnistSet &set, int epochs)
{
    float alpha = 1.0;

    n_features = set.rows*set.cols;

    std::vector<float> delta_digit;

    for (int i = 0; i < 10; i++)
    {
        std::vector<float> v(n_features);
        thetas.push_back(v);
    }

    InitRandomThetas();

    for (int i = 0; i < epochs; i++)
    {
        std::cout << "Epoch: " << i << "; Errors: " << CountErrors(set) << std::endl;

        auto sample = set.samples.begin();
        auto label = set.labels.begin();

        while (sample != set.samples.end())
        {
            std::vector < std::vector <float>> deltas;
            deltas.reserve(10);




            for (int j = 0; j < 10; j++)
            {
                float predicted = (CrossProduct(*sample, thetas[j]));

                auto it_feature_theta = thetas[j].begin();
                auto it_feature_sample = (*sample).begin();

                delta_digit.clear();
                delta_digit.reserve(n_features);
                while (it_feature_theta != thetas[j].end())
                {

                    float d = (*label).at(j);
                    float delta =  alpha * (d - (predicted > 0)) * (*it_feature_sample);
                    delta_digit.push_back(delta);

                    it_feature_theta++;
                    it_feature_sample++;
                }

                deltas.push_back(delta_digit);
            }

            //updating thetas



            for (int j = 0; j < 10; j++)
            {
                auto theta = thetas[i].begin();
                auto delta = deltas[i].begin();

                while (theta != thetas[i].end())
                {
                    (*theta) += (*delta);

                    theta++;
                    delta++;
                }
            }

            sample++;
            label++;

            //std::cout << '.';

        }

    }




}

Classifier::Classifier()
{
    InitRandomThetas();
}

int Classifier::CountErrors(const MnistSet &set) const
{
    auto it_samples = set.samples.begin();
    auto it_labels = set.labels.begin();


    int errors = 0;

    while (it_samples != set.samples.end())
    {
        std::vector <float> results (10,0);
        for (int i = 0; i < 10; i++) results[i] = CrossProduct((*it_samples),thetas[i]);



        if (std::distance(results.begin(), std::max_element(results.begin(),results.end(),[](float a, float b){return a < b;}))
                !=
                std::distance((*it_labels).begin(), std::max_element((*it_labels).begin(),(*it_labels).end(),[](float a, float b){return a < b;})) )
        {
            errors++;
        }

        it_samples++;
        it_labels++;

    }

    return errors;
}
