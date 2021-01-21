#include <iostream>

void fillIn(int beginning, int end, int table[]);  //table[] = *table
void displayTable();

void fillIn(int beginning, int end, int table[])
{
   
    for(int i = 0; i < 20; i++)
    {
        table[i] = rand() % end + beginning;
    }
}

void displayTable(int table[])
{
    for (int i = 0; i < 20; i++)
    {
        std::cout << table[0] << " ";
    }
}