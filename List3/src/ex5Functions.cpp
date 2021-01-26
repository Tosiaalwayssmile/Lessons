#pragma once
#include <iostream>
#include <cmath>
#include "ex5Functions.h"

bool pythagorasNumber(int a, int b, int c)
{
    if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(c, 2) + pow(b, 2) == pow(a, 2))
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