#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
#include <algorithm>    // std::sort

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
void createMatrixC(int** matrixX, int** matrixC);
void sortMatrix(int** matrix);
void sortMatrixRow(int** matrix);

void exercise2()
{
    std::cout << "Exercise 2." << std::endl;

    int** X = allocateMatrix();
    int** Y = allocateMatrix();

    srand(time(NULL));
    
    randomization(X, -5, 5);
    std::cout << std::setw(22) << "Matrix X" << std::endl << std::endl;
    display(X);

    randomization(Y, -5, 5);
    std::cout << std::endl << std::setw(22) << "Matrix Y" << std::endl << std::endl;
    display(Y);
   
    std::cout << "\nSum under diagonal in array X: " << sumUnderDiagonal(X) << std::endl;
    std::cout << "\nSum under diagonal in array Y: " << sumUnderDiagonal(Y) << std::endl;

    int** C = allocateMatrix();
    createMatrixC(X, C);
    std::cout << std::endl << std::setw(22) << "Matrix C" << std::endl << std::endl;
    display(C);

    sortMatrixRow(Y);
    std::cout << std::endl << "Sorting matrix Y in every row in descending order." << std::endl;
    std::cout << std::endl << std::setw(22) << "Matrix Y" << std::endl << std::endl;
    display(Y);

    sortMatrix(Y);
    std::cout << std::endl << "Sorting matrix Y in descending order." << std::endl;
    std::cout << std::endl << std::setw(22) << "Matrix Y" << std::endl << std::endl;
    display(Y);
    
    delMatrix(X);
    delMatrix(Y);
    delMatrix(C);
}

int** allocateMatrix()
{
    /* Dynamically alocates memory for new matrix. */

    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int [columns];
    }
    return matrix;
}

void randomization(int** matrix, int lowest, int highest)
{
    /* Fills passed matrix with random values from range <lowest, highest>. */
    
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
    /* Displays passed matrix as well as array indexes. */
    
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
    
    /* Here are displayed values. Code above makes it prettier... I mean cleaner. The output looks cleaner */

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
    /* Sums values under main matrix diagonal. */
    
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
    /* Deletes a dynamically alocated array. */

    for (int i = 0; i < rows; i++)
    {
        delete matrix[i];
    }
    delete [] matrix;
}

void createMatrixC(int** matrixX, int** matrixC)
{
    /* Fills passed matrix C with values from matrix X accordingly to formula given in ex. description. */
    
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            int minIK = 0, minPJ = 0;

            for(int k = 1; k < columns; k++)
            {
                 if (matrixX[i][k] < matrixX[i][minIK])
                 {
                     minIK = k;
                 }
            }

            for(int p = 1; p < columns; p++)
            {
                 if (matrixX[p][j] < matrixX[minPJ][j])
                 {
                     minPJ = p;
                 }
            }         
            matrixC[i][j] = matrixX[i][minIK] * matrixX[minPJ][j];
        }
    }
}

void sortMatrixRow(int** matrix)
{
    for (int i = 0; i < rows; i++)
    {
        std::sort(matrix[i], matrix[i] + rows, std::greater<int>()); 
    }
    

/*
    int temp = 0;
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if (matrix[i][j+1] > matrix[i][j])
            {
                temp = matrix[i][j+1];
                matrix[i][j+1] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }*/
}

void sortMatrix(int** matrix)
{
    int* tempArray;
    tempArray = new int[rows * columns];
    int index = 0;

    //Copy elements from a matrix to an array
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++, index++)
        {
            tempArray[index] = matrix[i][j];
        }
    }
    //Sorting an array
    
    std::sort(tempArray, tempArray + index); 

    index = rows * columns - 1;

    //Copy elements from the array to the matrix
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++, index--)
        {
            matrix[i][j] = tempArray[index];
        }
    }
    delete [] tempArray;
}

