#include <iostream>
#include <cmath>

using namespace std;

int main()
{
/********************************************************* ZADANIE 1 **********************************************************/
/**************** POLISH DESCRIPTION: Program, który wczytuje liczbę rzeczywistą i oblicza z niej pierwiastek. ****************/
/********************************** Działanie powtarzane jest dopóki nie zostanie wczytane 0. *********************************/

cout << "Program finding square root of a given integer number" << endl;
int number = 0;
do
{   
    cout << "Insert number: ";
    cin >> number;
    cout << "The square root of " +  std::to_string(number) + " is " << sqrt(number) << endl;
} while (number != 0);



/********************************************************* ZADANIE 2 **********************************************************/
/**************** POLISH DESCRIPTION: Program, który wczytuje liczbę rzeczywistą i oblicza z niej pierwiastek. ****************/
/********************************** Działanie powtarzane jest dopóki nie zostanie wczytane 0. *********************************/
return 0;
}