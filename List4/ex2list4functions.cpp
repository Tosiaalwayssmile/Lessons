#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iterator>
#include <vector>

void fillIn(int beginning, int end, int table[], int arrSize);  //table[] = *table
void displayTable(int table[], int arrSize);
void parityCheck(int *tableN, int *tableB, int arrSize);  //table[] = *table

void fillIn(int beginning, int end, int table[], int arrSize)
{
    for(int i = 0; i < arrSize; i++)
    {
        table[i] = rand() % (end - beginning + 1) + beginning;
        //table[i] = rand() % end + beginning;
        //std::cout <<  table[i] << " "; 
    }
    std::cout << std::endl;
}

void displayTable(int table[], int arrSize)
{
    //i//nt arrSize = sizeof(table)/sizeof(table[0]);
    //std::cout <<arrSize << std::endl;
    for (int i = 0; i < 20; i++)
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