#include <iostream>

int nFactorial (int n); 
int newtonSymbol (int n, int k);
int pascalTriangle (int rows);   

int nFactorial (int n)
{
    int nFactorial = n;
    while(n>1)
    {
        nFactorial *= (n-1);
        n--;
    }
    return nFactorial;
}

int newtonSymbol (int n, int k)
{
    return (nFactorial(n) / (nFactorial(k)* nFactorial(n-k)));
}

int pascalTriangle (int rows)
{
    //return (nFactorial(n) / (nFactorial(k)* nFactorial(n-k)));
}