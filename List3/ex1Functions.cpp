#include <iostream>

void setTo0Value(int a, int b);                     //arguments are passed to function by value
void setTo0Ref(int &a, int b);                      //arguments are passed to function by reference
void setTo0Ptr(int *a, int *b);                     //arguments are passed to function by pointer

void setTo0Value(int a, int b)  
{
    std::cout << "\nVersion 1. By value. (Nothing is modified)." << std::endl;
    a = 0;
    b = 0;
}
void setTo0Ref(int &a, int b)
{
    std::cout << "\nVersion 2. By reference. (Only \"a\" is passed by reference, so only \"a\" is modified)." << std::endl;
    a = 0;
    b = 0;
}
void setTo0Ptr(int *a, int *b)
{
    std::cout << "\nVersion 3. By pointer. (Both values are modified)." << std::endl;
    *a = 0;
    *b = 0;
}