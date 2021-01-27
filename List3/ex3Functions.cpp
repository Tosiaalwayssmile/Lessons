#include <iostream>
#include <cmath>

int nFactorial (int n); 
int newtonSymbol (int n, int k);
void pascalTriangle (int rows);

int nFactorial (int n)
{
    int nFactorial = 0;

    n = abs(n);     //in case of negative input change to absolute value

    if (n == 0) 
    {
        nFactorial = 1;
    }
    
    else
    {
        nFactorial = n;
        
        while(n > 1)
        {
            nFactorial *= (n - 1);
            n--;
        }  
    }
    return nFactorial;
}

int newtonSymbol (int n, int k)
{
    return (nFactorial(n) / (nFactorial(k)* nFactorial(n - k)));
}

void pascalTriangle (int rows)
{
    int value = 1;
    for(int i = 0; i < rows; i++)
    {
        for(int space = 1; space <= rows - i; space++)   // Spaces from the left to the values, with each iterations there's
        {
            std::cout <<"  ";                          // less of them
        }
        for(int j = 0; j <= i; j++)
        {
            if (j == 0 || i == 0)                      // For the 1st and the 2sd row and the first value to the left there is only possible '1' 
            {
                value = 1;
            }
            else
            {   
                value = value *(i - j + 1) / j;
            }
            std::cout << value << "   ";
        }
        std::cout << std::endl;
    }
}