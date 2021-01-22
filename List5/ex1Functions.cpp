#include <iostream>

void fillIn(int lowest, int highest, int groupPoints[], int groupSize);
void summary(int groupPoints[], int groupSize);
float average(int groupPoints[], int groupSize);

void fillIn(int lowest, int highest, int groupPoints[], int groupSize)
{
    for(int i = 0; i < groupSize; i++)
    {
        groupPoints[i] = rand() % (highest - lowest + 1) + lowest;
    }
}

void summary(int groupPoints[], int groupSize)
{   
    int summary[11] = {0};
    int counter = 0;
    for(int i = 0; i <= 10; i++)
    {
        for(int j = 0; j < groupSize; j++)
        {
            if (groupPoints[j] == i)
            {
                counter++;
                summary[i] = counter;
            }
        }
        std::cout << i << " points gave: " << summary[i] << " people." << std::endl;
        counter = 0;
    }
    std::cout << std::endl;
}

float average(int groupPoints[], int groupSize)
{   
    int sum = 0;

    for(int i = 0; i < groupSize; i++)
    {
        sum += groupPoints[i];
    }
    return sum / groupSize;
}