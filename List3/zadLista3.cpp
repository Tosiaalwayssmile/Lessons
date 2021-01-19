#include <iostream>
#include "ex1Functions.cpp"
#include "ex2Functions.cpp"

int main()
{
    /********************************************************* ZADANIE 1 **********************************************************/
    /*Zdefiniować dwie zmienne a i b. Napisać funkcję zerującą podane wartości i wyświetlającą je przed i po zerowaniu. 
    Utworzyć dwie wersję takiej funkcji, różniące się sposobem przekazywania jednego z argumentów:
    – przekazać argumenty przez wartość,
    – jeden z argumentów przekazać przez referencję.
    Wyświetlić wartości parametrów a i b przed wywołaniem funkcji, wywołać funkcję od a i b,
    wyświetlić wartości a i b po wywołaniu funkcji.
    */
    std::cout << "******************************************************************************************************************************" 
                 "\nEx.1 Program passing variables to functions which set them to 0." 
                 "Each function is an example of different function call method." 
                 "\n******************************************************************************************************************************" << std::endl;
    int a = 3004, b = 69;
    std::cout << "Before changing values a = " << a << ", b = " << b << std::endl;
    setTo0Value(a,b);
    std::cout << "After setting to zero by setTo0Value(a,b); a = " << a << ", b = " << b << std::endl;
    setTo0Ref(a,b);
    std::cout << "After setting to zero by etTo0Ref(a,b); a = " << a << ", b = " << b << std::endl;
    a = 3004;  // change a to previous value so both values can be changed again to 0
    std::cout << "Setting values a and b to original form. Current value of a = " << a << ", b = " << b <<  "." << std::endl;
    setTo0Ptr(&a, &b);
    std::cout << "After setting to zero bys setTo0Ptr(&a, &b); a = " << a << ", b = " << b <<  "." << std::endl;

    /********************************************************* ZADANIE 2 **********************************************************/
    /*Napisać funkcję bez typu (void) zwielokrotniającą n-razy wartość zmiennej przekazywanej przez referencję 
    (n – przekazywane przez argument). */
    std::cout << "\n**************************************************************" 
                 "\nEx.2 Program multiplying variable by input-given amount." 
                 "\n**************************************************************" << std::endl;
    a = 12;
    return 0;
}



