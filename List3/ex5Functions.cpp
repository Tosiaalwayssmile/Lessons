#include <iostream>
#include <cmath>

bool pythagorasNumber(int a,int b,int c);
int greatesCommonDivisor(int a, int b);

bool pythagorasNumber(int a,int b,int c)
{
    if (pow(a,2) + pow(b,2) == pow(c,2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int greatesCommonDivisor(int a, int b)
{
    while(a != b)
    {
        if(a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}