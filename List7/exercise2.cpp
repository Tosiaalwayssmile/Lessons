#include <iostream>
#include <iomanip> 

#define rows 5
#define columns 5

/* Zadeklarować dwie tablice X i Y o 5-wierszach i 5-kolumnach.
1. Napisać funkcję, która losuje elementy tablicy z przedziału <-5, 5>. Wylosować tablice X i Y.
2. Napisać funkcję, która wypisuje na ekran elementy wylosowanej tablicy. Wypisać tablice X i Y.
3. Napisać funkcję, która oblicza i zwraca sumę elementów leżących pod przekątną. Obliczyć
sumę dla tablicy X i Y.


4. Zadeklarować macierz C o 5-wierszach i 5-kolumnach.
5. Napisać funkcję, która tworzy macierz C o 5-wierszach i 5-kolumnach w następujący sposób
C[i][j]=min(X[i][k]) * min(X[p][j])
 k=0,...,4 p=0,...,4
6. Uporządkować malejąco elementy w każdym wierszu macierzy Y. 
*/

int** allocateMatrix();
void randomization(int** matrix, int lowest, int highest);
void display(int** matrix);
int sumUnderDiagonal(int** matrix);
void delMatrix(int** matrix);

void exercise2()
{
    std::cout << "Exercise 2." << std::endl << std::endl;

    int** X = allocateMatrix();
    int** Y = allocateMatrix();

    srand(time(NULL));
    
    randomization(X, -5, 5);
    std::cout << "Matrix X" << std::endl << std::endl;
    display(X);

    randomization(Y, -5, 5);
    std::cout << "\nMatrix Y" << std::endl << std::endl;
    display(Y);
   
    std::cout << "\nSum under diagonal in array X: " << sumUnderDiagonal(X) << std::endl;
    std::cout << "\nSum under diagonal in array Y: " << sumUnderDiagonal(Y) << std::endl;

    delMatrix(X);
    delMatrix(Y);
}

int** allocateMatrix()
{
    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int [columns];
    }
    return matrix;
}

void randomization(int** matrix, int lowest, int highest)
{
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            matrix[i][j] = rand() % (highest-(lowest) +1) + (lowest);
        }
    }
}

void display(int** matrix)
{
    std::cout << " " << " " << " ";
    for (int i = 0; i < rows; i++)
    {
        std::cout << std::setw(6) << i;
    }
    std::cout << std::endl << " ";

    for (int i = 0; i < rows; i++)
    {
        std::cout << std::setw(6) << "=======" ;
    }
    std::cout << std::endl;
    
    for (int i = 0; i < rows; i++)
    {
        std::cout << " " << i << "|";
        
        for(int j = 0; j < columns; j++)
        {
            std::cout << std::setw(6) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

int sumUnderDiagonal(int** matrix)
{
    int sum = 0;
    for (int j = 0; j < columns; j++)
    {
        for(int i = j+1; i < rows; i++)
        {
            sum += matrix[i][j];
        }
    }
   return sum;
}

void delMatrix(int** matrix)
{
    for (int i = 0; i < rows; i++)
    {
        delete matrix[i];
    }
    delete [] matrix;
}