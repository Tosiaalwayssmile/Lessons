#include <iostream>
#include <algorithm>

void fillIn(int lowest, int highest, int groupPoints[], int groupSize);
void summary(int groupPoints[], int groupSize, int summaryPoints[]);
float average(int groupPoints[], int groupSize);
float median(int groupPoints[], int groupSize);
void mode(int summaryPoints[], int pointsRange);

void fillIn(int lowest, int highest, int groupPoints[], int groupSize)
{
    for(int i = 0; i < groupSize; i++)
    {
        groupPoints[i] = rand() % (highest - lowest + 1) + lowest;
    }
}

void summary(int groupPoints[], int groupSize, int summaryPoints[])
{   
    for(int i = 0; i <= 10; i++)
    {
        for(int j = 0; j < groupSize; j++)
        {
            if (groupPoints[j] == i)
            {
                summaryPoints[i]++;
            }
        }
        std::cout << i << " points gave:  " << summaryPoints[i] << " people." << std::endl;
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
    return (float)sum / (float)groupSize;       //Need to first cast integers to float before doing the calculation
}


float median(int groupPoints[], int groupSize)
{   

    std::sort(groupPoints, groupPoints + groupSize);        // sort from lowest to highest

    if (groupSize % 2)      //if middle value is median
    {
        return groupPoints[groupSize / 2];      //return median AKA value in the middle of sorted array
    }
    
    else        // average of two middle values equals median
    {
        return (groupPoints[groupSize / 2] + groupPoints[groupSize / 2 + 1]) / 2;
    }
}

template <typename T> void displayTable(T table[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << table[i] << " ";
    }
    std::cout << std::endl;
}

void mode(int summaryPoints[], int pointsRange)
{   
    int mode = 0;
    for (int i = 1; i < pointsRange; i++)
    {
        if(summaryPoints[i] > summaryPoints[mode])
        {
            mode = i;
        }
    }
    for (int i = 0; i < pointsRange; i++)
    {
        if(summaryPoints[i] == summaryPoints[mode])
        {
            std::cout << "Mode equals: " << i << std::endl;
        }
    }
}

void histogram(int summaryPoints[], int pointsRange)
{   
    for (int i = 0; i < pointsRange; i++)
    {
        std::cout << "\n" << i << " points  ";
        if(i == 10)
            {
                std::cout << "\b";
            }
        while(summaryPoints[i])
        {
            std::cout << "#";
            summaryPoints[i]--;
        }
    }
}
