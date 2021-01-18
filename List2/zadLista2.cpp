#include <iostream>
#include <cmath>  // Need it for square roots
#include <cstdlib>

//using namespace std;

std::string inputValidation(std::string type)
{
    std::string input = "null";
    bool flaga = 0;
    while (!flaga)
    {
        std::cin >> input;
        if (type == "int" || type == "integer") 
        {
            if (isdigit(input[0]))
            {
                flaga = 1;
                std::cout << "Noice, you entered a valid value" << std::endl;
            }
            else
            {
                std::cout << "Error. Invalid value, re-enter: ";
            }
        }
        else if (type == "float") 
        {
            if (isdigit(input[0]))
            {
                flaga = 1;
                std::cout << "Good job, you entered a valid value" << std::endl;
            }
            else
            {
                std::cout << "Error. Invalid value, re-enter: " << std::endl;
            }
        }
        else
            std::cout << "Error in code, check function parameter when calling function" << std::endl;
    }
    return input;
}

int main()
{
/********************************************************* ZADANIE 1 **********************************************************/
/**************** POLISH DESCRIPTION: Program, który wczytuje liczbę rzeczywistą i oblicza z niej pierwiastek. ****************/
/********************************** Działanie powtarzane jest dopóki nie zostanie wczytane 0. *********************************/

std::cout << "Ex.1 Program finding square root of a given integer number. To quit insert \'0\'." << std::endl;
int number = 1;
while (number != 0)
{  
    std::cout << "Insert a number: ";
    number = stoi(inputValidation("integer")); // check if input is valid then convert to needed type
    std::cout << "The square root of " +  std::to_string(number) + " is " << sqrt(number) << std::endl;
} 

/********************************************************* ZADANIE 2 **********************************************************/
/**************** POLISH DESCRIPTION: Program, który wczytuje dwie liczby rzeczywiste i działanie jakie ma być na nich wykonane. ****************/
/******************************** Wykonać odpowiednie działanie i wyświetlić jego wynik. Użyć instrukcji switch. ********************************/
std::cout << "*************************************************************************************" << std::endl;
std::cout << "Ex.2 Basic calculator. First enter 2 integer numbers and then select an operation." << std::endl;
int number1 = 0, number2 = 0, operation = 0;
char stop = 'y';
do{
    std::cout << "*************************************************************************************" << std::endl;
    std::cout << "Insert the first number: ";
    number1 = stoi(inputValidation("integer")); // check if input is valid then convert to needed type
    std::cout << "Insert the second number: ";
    number2 = stoi(inputValidation("integer")); // check if input is valid then convert to needed type
    std::cout << "Press \'1\' to add numbers\n"
            "Press \'2\' to subtract\n"
            "Press \'3\' to multiply\n" 
            "Press \'4\' to divide" << std::endl;
    std::cout << "Choose operation type (1-4): ";
    operation = stoi(inputValidation("integer")); // check if input is valid then convert to needed type
    switch(operation)
    {
      case 1:
      {
          std::cout << "The sum of given numbers equals: " << number1 + number2 << std::endl;
          break;
    }
      case 2:
      {
          std::cout << "The difference of given numbers equals: " << number1 - number2 << std::endl;
          break;
      }
      case 3:
      {
          std::cout << "The multiplication of given numbers equals: " << number1 * number2 << std::endl;
          break;
      }
      case 4:
      {
          std::cout << "The division of given numbers equals: " << (float)number1 / number2 << std::endl;
          break;
      }
      default:
      {
          std::cout << "Invalid input." << std::endl;
          break;
      }
    } 
    std::cout << "Do you wish to continue y/n: ";
    std::cin >> stop;
}while(stop!='n' && stop=='y');

/********************************************************* ZADANIE 3 **********************************************************/
/**************** POLISH DESCRIPTION: Program, który wczytuje liczbę naturalną oraz znak, a następnie znajduje ****************/
/************************ liczbę cyfr podanej liczby, sumę jej cyfr lub pierwszą najbardziej znaczącą cyfrę. ******************/
std::cout << "*************************************************************************************" << std::endl;
std::cout << "Ex.3 Program calculating some stuff depending on an input" << std::endl;
std::cout << "*************************************************************************************" << std::endl;
do
{
    std::cout << "Insert a natural number: ";
    std::string naturalNumber = (inputValidation("integer")); // check if input is valid then convert to needed type
    std::cout << "Press a or A to find the number of digits" 
                 "\nPress b or B to find the sum of digits"
                 "\nPress c or C to find first most siginificant digit: ";
    char userInput = 'f';
    std::cin >> userInput;
    switch(userInput)
    {
        case 'a':
        case 'A':
        {   
            std::cout << "Number of digits in given number equals: " << naturalNumber.size() << std::endl;
            break;
        }
        case 'b':
        case 'B':
        {
            int i = 0;
            int sum = 0;
            for(int i = 0; i < naturalNumber.size(); i++)
                {
                    sum += naturalNumber[i] - '0';  //Since it adds ascii value we need to subtract '0' or 32 to see the result in decimal
                 }
            std::cout << "The sum of digits equals: " << sum << std::endl;
            break;
        }
        case 'c':
        case 'C':
        {
            int msDigit = 0;
            int naturalNumberINT = stoi(naturalNumber);
            int lastDigit = 0;
            while (naturalNumberINT)
            {
                lastDigit = naturalNumberINT%10;        //we check here from the end of the string if there is a greater digit
                msDigit = std::max(lastDigit,msDigit);       //if a digit is greater than lastdigit we set it as a new maximum
                naturalNumberINT = naturalNumberINT/10; //then we move on to check another digit on the left
            }
            std::cout << "The most significant digit is: " << msDigit << std::endl;
            break;
        }
        default:
        {   
            std::cout << "Invalid input." << std::endl;
            break;
        }
    }
    std::cout << "Do you wish to continue y/n: ";
    std::cin >> stop;
}while(stop!='n' && stop=='y');
/********************************************************* ZADANIE 4 **********************************************************/
/**************** POLISH DESCRIPTION: Program, który wczytuje liczbę całkowitą, a następnie wykonuje ****************/
/****************************************** na jej podstawie wybrane działanie. *************************************/
std::cout << "Ex.4 Program calculating some stuff depending on an input" << std::endl;
do{
    std::cout << "Press \'1\' 2^n - 2 to the power of n \n"
                 "Press \'2\' x^n - x to the power of n \n"
                 "Press \'3\' n! - n factorial" << std::endl;
    std::cout << "Choose operation type (1-3): ";
    operation = stoi(inputValidation("integer")); // check if input is valid then convert to needed type
    int exponent = 0;
    float base = 0;
    switch(operation)
    {
        case 1:
        {
            std::cout << "Insert exponent (natural number): ";
            exponent = stoi(inputValidation("integer")); // check if input is valid then convert to needed type
            std::cout << "2 to the power of " << exponent << " equals " << pow(2,exponent) << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "Insert base (x - real number): ";
            base = stof(inputValidation("float")); // check if input is valid then convert to needed type
            std::cout << "Insert exponent (n - natural number): ";
            exponent = stoi(inputValidation("integer")); // check if input is valid then convert to needed type
            std::cout << base << " to the power of " << exponent << " equals " << pow(base,exponent) << std::endl;
            break;
        }
        case 3:
        {
            number = 0;
            while(number < 1)
            {
                std::cout << "Insert n (natural number): ";
                number = stoi(inputValidation("integer")); // check if input is valid then convert to needed type
            }
            int factorial = 1;
            int counter = number;
            while(counter)
            {
                factorial *= counter;
                counter--;
            }
            std::cout << number << "!" << " equals " << factorial << std::endl;
            break;
        }
        default:
        {
            std::cout << "Invalid input." << std::endl;
            break;
        }
    }
std::cout << "Do you wish to continue y/n: ";
std::cin >> stop;
}while(stop!='n' && stop=='y');

std::cout << "Thanks for stopping by :)." << std::endl;
return 0;
}