#pragma once
#include <iostream>
#include "ex1Functions.h"

void setTo0Value(float a, float b)  //arguments are passed to function by value
{
    std::cout << "\nVersion 1. By value. (Nothing is modified)." << std::endl;
    a = 0;
    b = 0;
}
void setTo0Ref(float &a, float b)   //arguments are passed to function by reference
{
    std::cout << "\nVersion 2. By reference. (Only \"a\" is passed by reference, so only \"a\" is modified)." << std::endl;
    a = 0;
    b = 0;
}
void setTo0Ptr(float *a, float *b)  //arguments are passed to function by pointer
{
    std::cout << "\nVersion 3. By pointer. (Both values are modified)." << std::endl;
    *a = 0;
    *b = 0;
}