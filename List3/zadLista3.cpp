#include <iostream>
#include "ex1Functions.cpp"
#include "ex2Functions.cpp"
#include "ex3Functions.cpp"
#include "inputValidation.cpp"


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
    std::cout << "Insert multiplier: ";
    int multiplier = 0;
    multiplier = stoi(inputValidation("integer")); // check if input is valid then convert to needed type
    std::cout << a << " multiplied by " << multiplier;
    multiply(multiplier, a);
    std::cout << " equals " << a << "." << std::endl;

    /********************************************************* ZADANIE 3 **********************************************************/
    /*Napisać funkcję:
    – obliczającą silnię n! w sposób iteracyjny,
    – obliczającą wartość symbolu Newtona – wykorzystać poprzednią funkcję,
    – wyświetlającą trójkąt Pascala o podanej liczbie wierszy.
    */
    std::cout << "\n**************************************************************" 
                 "\nEx.3 Program calculating n!, Newton symbol and displaying pascal triangle." 
                 "\n**************************************************************" << std::endl;

    std::cout << "Insert a positive integer for n!: ";
    int n = 0;      // n for n! or n factorial
    n = stoi(inputValidation("integer"));
    std::cout << "N factorial. " << n << "! euals " << nFactorial(n) << std::endl;    
    
    std::cout << "Insert a positive integer for k: ";
    int k = 0;      // k for Newton symbol
    k = stoi(inputValidation("integer"));
    std::cout << "Newton symbol. " << n << " choose " << k << " euals " << newtonSymbol(n,k) << std::endl;    


    return 0;
}



