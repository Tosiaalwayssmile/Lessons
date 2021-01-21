#include <iostream>

void changeData(float monthlyIncome[]);
void incomeMinMax(float monthlyIncome[], int arrSize, std::string months[]);
float average(float monthlyIncome[], int arrSize);
void checkNegativeValues(float monthlyIncome[], int arrSize);

void changeData(float monthlyIncome[])
{
    int i = 0;
    std::cout << "Insert month id for which you want to change data (1-12): ";
    std::cin >> i;
    std::cout << "Previous income value for given month: " << monthlyIncome[i - 1] << std::endl;
    std::cout << "Insert new income: ";
    std::cin >> monthlyIncome[i - 1];
}

void incomeMinMax(float monthlyIncome[], int arrSize, std::string months[])
{
    int maxID = 0, minID = 0;
    for (int i = 0; i < arrSize; i++)
    {        
        if(monthlyIncome[i] > monthlyIncome[maxID])
        {
            maxID = i;
        }
        if(monthlyIncome[i] < monthlyIncome[minID])
        {
            minID = i;
        }
    }
    std::cout << "Max income was for month: " << months[maxID] << " and equals " << monthlyIncome[maxID] << std::endl;
    std::cout << "Min income was for month: " << months[minID] << " and equals " << monthlyIncome[minID] << std::endl;
}

float average(float monthlyIncome[], int arrSize)
{
    float sum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        sum += monthlyIncome[i];
    }   
    return sum/arrSize;  
}

void checkNegativeValues(float monthlyIncome[], int arrSize, std::string months[])
{
    int counter = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if(monthlyIncome[i] < 0)
        {
            counter++;
            std::cout << "In month: " << months[i] << std::endl;
        }
    } 
    std::cout << "The company had negative income " <<  counter << " times throughout the year." << std::endl;  
}