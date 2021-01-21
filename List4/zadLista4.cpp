#include <iostream>
#include "ex2list4functions.cpp"
#include "inputValidation.cpp"

int main()
{
    /********************************************************* ZADANIE 2 **********************************************************/
    /* Napisac program skladajacy sie z funkcji. W programie zadeklarowac jednowymiarowa tablice N[20] zawierajca liczby calkowite.
    1. Tablice wypelnic liczbami losowymi z przedzialu podanego przez uzytkownika.
    2. Utworzyc tablice jednowymiarowa B, przepisujac do niej najpierw elementy nieparzyste, a nastepnie elementy parzyste tablicy N.
    3. Wyswietlic elementy tablicy na ekranie.
    */
    std::cout << "Ex.2 Working with tables: random filling and sorting" << std::endl;
    int N[20], B[20];
    int beginning = 0, end = 0;
    std::cout << "Insert number range beginning: ";
    beginning = stoi(inputValidation("integer"));
    std::cout << "Insert number range end: ";
    end = stoi(inputValidation("integer"));
    srand(time(NULL));
    fillIn(beginning,end,N);
    //Utworzyc tablice jednowymiarowa B, przepisujac do niej najpierw elementy nieparzyste, a nastepnie elementy parzyste tablicy N.
    displayTable(N);
    return 0;
}

int *wsk = nullptr;