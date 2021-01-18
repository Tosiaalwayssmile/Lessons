#include <iostream>
#include <cmath>

using namespace std;

int main()
{
/********************************************************* ZADANIE 1 **********************************************************/
/**************** POLISH DESCRIPTION: Program, który wczytuje liczbę rzeczywistą i oblicza z niej pierwiastek. ****************/
/********************************** Działanie powtarzane jest dopóki nie zostanie wczytane 0. *********************************/

cout << "Program finding square root of a given integer number. To quit insert \'0\'." << endl;
int number = 0;
/************** Version with do .. while instead od while *************************
do
{   
    cout << "Insert number: ";
    cin >> number;
    cout << "The square root of " +  std::to_string(number) + " is " << sqrt(number) << endl;
} while (number != 0);
*/
number = 1;
while (number != 0)
{   
    cout << "Insert number: ";
    cin >> number;
    cout << "The square root of " +  std::to_string(number) + " is " << sqrt(number) << endl;
} 

/********************************************************* ZADANIE 2 **********************************************************/
/**************** POLISH DESCRIPTION: Program, który wczytuje dwie liczby rzeczywiste i działanie jakie ma być na nich wykonane. ****************/
/******************************** Wykonać odpowiednie działanie i wyświetlić jego wynik. Użyć instrukcji switch. ********************************/
cout << "*************************************************************************************" << endl;
cout << "\nBasic calculator. First enter 2 integer numbers and then select an operation." << endl;
int number1 = 0, number2 = 0, operation = 0;
char stop = 'y';
do{
    cout << "*************************************************************************************" << endl;
    cout << "Insert first number: ";
    cin >> number1;
    cout << "Insert second number: ";
    cin >> number2;
    cout << "Press \'1\' to add numbers\n"
            "Press \'2\' to subtract\n"
            "Press \'3\' to multiply\n" 
            "Press \'4\' to divide" << endl;
    cout << "Choose operation type (1-4): ";
    cin >> operation;
    switch(operation)
    {
      case 1:
      {
          cout << "The sum of given numbers equals: " << number1 + number2 << endl;
          break;
    }
      case 2:
      {
          cout << "The difference of given numbers equals: " << number1 - number2 << endl;
          break;
      }
      case 3:
      {
          cout << "The multiplication of given numbers equals: " << number1 * number2 << endl;
          break;
      }
      case 4:
      {
          cout << "The division of given numbers equals: " << (float)number1 / number2 << endl;
          break;
      }
    } 
    cout << "Do you wish to continue y/n: ";
    cin >> stop;
}while(stop!='n' && stop=='y');

/********************************************************* ZADANIE 3 **********************************************************/
/**************** POLISH DESCRIPTION: Program, który wczytuje liczbę naturalną oraz znak, a następnie znajduje. ****************/
/**************************** liczbę jej cyfr, sumę jej cyfr lub pierwszą najbardziej znaczącą cyfrę. **************************/
cout << "*************************************************************************************" << endl;
cout << "Program doing stuff" << endl;



return 0;
}