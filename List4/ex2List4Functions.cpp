#include <iostream>

void fillIn(int beginning, int end, int table[], int arrSize);  //table[] = *table
template <typename T> void displayTable(T table[], int arrSize);
void parityCheck(int *tableN, int *tableB, int arrSize);  //table[] = *table

void fillIn(int beginning, int end, int table[], int arrSize)
{
    for(int i = 0; i < arrSize; i++)
    {
        table[i] = rand() % (end - beginning + 1) + beginning;
    }
    std::cout << std::endl;
}

template <typename T> void displayTable(T table[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << table[i] << " ";
    }
    std::cout << std::endl;
}

void parityCheck(int *tableN, int *tableB, int arrSize)
{
    int j = 0;
    for (int i = 0; i < 20; i++)
    {
        if (tableN[i] % 2 != 0)   //first copy odd numbers from tableN to tableB
        {
            tableB[j] = tableN[i];
            j++;

        }
    }
    for (int i = 0; i < 20; i++)
    {
        if (tableN[i] % 2 == 0)     //then copy even numbers from tableN to tableB
        {
            tableB[j] = tableN[i];
            j++;
        }
    }
}