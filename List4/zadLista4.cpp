#include <iostream>
#include "ex1List4Functions.cpp"
#include "ex2List4Functions.cpp"
#include "inputValidation.cpp"

int main()
{
    /********************************************************* ZADANIE 1 **********************************************************/
    /* Napisac program umożliwiający obliczenie na podstawie miesięcznych przychodów firmy:
    1. Jaki był wynik maksymalny, a jaki minimalny i w ktorym miesiącu.
    2. Średniego wyniku firmy.
    3. Ile razy firma zanotowala straty i w jakich miesiacach. */

    std::cout << "*******************************************" 
                 "\nEx.1 Analyzing yearly income of a company."
                 "\n*******************************************" << std::endl;

    float monthlyIncome[12] = {100, 240.5, -300, 24, 30.7, 127, 
                               -56, 46.56, -17.5, 600, 236, 120.5};     // income data

    std::string months[12] = {"January", "February", "March", "April", "May", "June", 
                              "July", "August", "September", "October", "November", "December"};

    int arrSize = *(&monthlyIncome + 1) - monthlyIncome;    //get array size
    char stopSign = 'y';
    char stopSign2 = 'y';

    while(stopSign != 'n')
    {
        std::cout << "Choose: "
                  "\n\'1\' for displaying monthly incomes"
                  "\n\'2\' for changing monthly income data"
                  "\n\'3\' for seeing months with max and min income"
                  "\n\'4\' for seeing yearly average"
                  "\n\'5\' for checking how many times company made negative income and when: ";

        int operation = 0;    
        operation = stoi(inputValidation("integer"));
        std::cout << std::endl;

        switch(operation)
        {
            case 1:
            {
                displayTable<float>(monthlyIncome, arrSize);
                std::cout << std::endl;
                break;
            }
            case 2:
            {
                while(stopSign2 != 'n')
                {
                    changeData(monthlyIncome);
                    std::cout << "Do you wish to change more monthly income data? Y/n: ";
                    std::cin >> stopSign2;
                } 
                break;
            }
            case 3:
            {
                incomeMinMax(monthlyIncome, arrSize, months);
                break;
            }
            case 4:
            {
                std::cout << "Average monthly income equals: " << average(monthlyIncome, arrSize) << std::endl;
                break;
            }
            case 5:
            {
                checkNegativeValues(monthlyIncome, arrSize, months);
                break;
            }
            default:
            {
                std::cout << "You entered an incorrect value." << std::endl;
                break;
            }
        }
    std::cout << "Do you wish to choose another operation? Y/n: ";
    std::cin >> stopSign;
    std::cout << std::endl; // system clear
    }

    /********************************************************* ZADANIE 2 **********************************************************/
    /* Napisac program skladajacy sie z funkcji. W programie zadeklarowac jednowymiarowa tablice N[20] zawierajca liczby calkowite.
    1. Tablice wypelnic liczbami losowymi z przedzialu podanego przez uzytkownika.
    2. Utworzyc tablice jednowymiarowa B, przepisujac do niej najpierw elementy nieparzyste, a nastepnie elementy parzyste tablicy N.
    3. Wyswietlic elementy tablicy na ekranie.*/
 
    std::cout << "**********************************************************************" 
                 "\nEx.2 Working with tables: random filling and checking if odd or even."
                 "\n**********************************************************************" << std::endl;
    
    int N[20], B[20];
    int beginning = 0, end = 0;

    std::cout << "Insert number range beginning: ";
    beginning = stoi(inputValidation("integer"));

    std::cout << "Insert number range end: ";
    end = stoi(inputValidation("integer"));

    while (beginning > end)
    {
        std::cout << "End must be greater than beginning. Insert number range end: ";
        end = stoi(inputValidation("integer"));
    }
    srand(time(NULL));
    int arrSize1 = *(&N + 1) - N;       //get array size
    int arrSize2 = *(&B + 1) - B;       //get array size

    fillIn(beginning, end, N, arrSize1);
    std::cout << "Table N:" << std::endl;

    displayTable<int>(N, arrSize1);
    parityCheck(N, B, arrSize2);  
    
    std::cout << "\nTable B:" << std::endl;
    displayTable<int>(B, arrSize2);  
    std::cout << "\nThanks for stopping by :)" << std::endl;
    return 0;
}

