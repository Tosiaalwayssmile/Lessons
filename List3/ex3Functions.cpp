#include <iostream>

int nFactorial (int n);    

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