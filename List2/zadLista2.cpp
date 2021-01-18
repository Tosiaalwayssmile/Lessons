#include <iostream>
#include <cmath>

using namespace std;

string inputValidation(std::string type)
{
    string input = "null";
    bool flaga = 0;
    while (!flaga)
    {
        std::cin >> input;
        if (type == "int" || type == "integer") 
        {
            if (isdigit(input[0]))
            {
                flaga = 1;
                std::cout << "Noice, you entered a valid value" << endl;;
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
                std::cout << "Good job, you entered a valid value" << endl;;
            }
            else
            {
                std::cout << "Error. Invalid value, re-enter: " << endl;
            }
        }
        else
            std::cout << "Error in code, check function parameter when calling function" << endl;
    }
    return input;
}

int main()
{
/********************************************************* ZADANIE 1 **********************************************************/
/**************** POLISH DESCRIPTION: Program, który wczytuje liczbę rzeczywistą i oblicza z niej pierwiastek. ****************/
/********************************** Działanie powtarzane jest dopóki nie zostanie wczytane 0. *********************************/

std::cout << "Program finding square root of a given integer number. To quit insert \'0\'." << endl;
int number = 1;
while (number != 0)
{  
    std::cout << "Insert a number: ";
    number = stoi(inputValidation("integer"));
    std::cout << "The square root of " +  std::to_string(number) + " is " << sqrt(number) << endl;
} 

/********************************************************* ZADANIE 2 **********************************************************/
/**************** POLISH DESCRIPTION: Program, który wczytuje dwie liczby rzeczywiste i działanie jakie ma być na nich wykonane. ****************/
/******************************** Wykonać odpowiednie działanie i wyświetlić jego wynik. Użyć instrukcji switch. ********************************/
std::cout << "*************************************************************************************" << endl;
std::cout << "Basic calculator. First enter 2 integer numbers and then select an operation." << endl;
int number1 = 0, number2 = 0, operation = 0;
char stop = 'y';
do{
    std::cout << "*************************************************************************************" << endl;
    std::cout << "Insert the first number: ";
    number1 = stoi(inputValidation("integer"));
    std::cout << "Insert the second number: ";
    number2 = stoi(inputValidation("integer"));
    std::cout << "Press \'1\' to add numbers\n"
            "Press \'2\' to subtract\n"
            "Press \'3\' to multiply\n" 
            "Press \'4\' to divide" << endl;
    std::cout << "Choose operation type (1-4): ";
    operation = stoi(inputValidation("integer"));
    switch(operation)
    {
      case 1:
      {
          std::cout << "The sum of given numbers equals: " << number1 + number2 << endl;
          break;
    }
      case 2:
      {
          std::cout << "The difference of given numbers equals: " << number1 - number2 << endl;
          break;
      }
      case 3:
      {
          std::cout << "The multiplication of given numbers equals: " << number1 * number2 << endl;
          break;
      }
      case 4:
      {
          std::cout << "The division of given numbers equals: " << (float)number1 / number2 << endl;
          break;
      }
      default:
      {
          cin.clear();  //no idea if needed
          cin.sync();
          std::cout << "Invalid input." << endl;
          break;
      }
    } 
    std::cout << "Do you wish to continue y/n: ";
    cin >> stop;
}while(stop!='n' && stop=='y');

/********************************************************* ZADANIE 3 **********************************************************/
/**************** POLISH DESCRIPTION: Program, który wczytuje liczbę naturalną oraz znak, a następnie znajduje ****************/
/************************ liczbę cyfr podanej liczby, sumę jej cyfr lub pierwszą najbardziej znaczącą cyfrę. ******************/
std::cout << "*************************************************************************************" << endl;
std::cout << "Program calculating some stuff" << endl;
std::cout << "*************************************************************************************" << endl;
std::cout << "Insert a natural number: ";
string naturalNumber = (inputValidation("integer"));
std::cout << "Press a or A to find the number of digits" 
             "\nPress b or B to find the sum of digits"
             "\nPress c or C to find first most siginificant digit: ";
char userInput = 'null';
cin >> userInput;
switch(userInput)
{
    case 'a':
    case 'A':
    {   
        int numberOfDigits = 0;
        for (int i = 0; naturalNumber[i]; i < naturalNumber.size())
        {
          //  numberOfDigits++;
        }
       // cout << numberOfDigits << endl;
        break;
    }
    case 'b':
    case 'B':
    {
        cout << "f" << endl;
        break;
    }
    case 'c':
    case 'C':
    {
        cout << "f" << endl;
        break;
    }
}

return 0;
}