//int *wsk = nullptr;
#include <iostream>
#include "ex1Functions.cpp"

#define groupSize 100

int main()
{
    /* ******************************** ZADANIE *****************************************
    Grupę 100 osób poproszono o ocenę filmu. Każdy mógł przyznać punkty od 0 do 10.
    1. Zadeklarować tablicę 100-elementową.
    2. Wylosować elementy tej tablicy z przedziału <0, 10>.
    3. Podsumować wyniki głosowania tzn. obliczyć ile osób przyznało 0 punktów, 1 punkt, 2 punkty itp.
    4. Obliczyć średnią liczbę punktów.
    ####DONE#####
    5. Obliczyć medianę (środkowa wartość w posortowanej tablicy, w przypadku parzystej
    liczby elementów tablicy jest to średnia dwóch środkowych wartości).
    6. Obliczyć dominantę (najczęściej występującą wartość, w przypadku kilku
    jednakowych wartości podać wszystkie) .
    7. Narysować histogram złożony z #. Histogram pokazuje liczebności poszczególnych
    grup.
    Program podzielić na funkcje. Rozmiar tablicy ustalić za pomocą dyrektywy definiującej. */

    std::cout << "*******************************************************************" 
                 "\nEx.1 Program analyzing data from array filled with random numbers." 
                 "\n******************************************************************" << std::endl;

    int groupPoints[groupSize];
    srand(time(NULL));
    fillIn(0, 10, groupPoints, groupSize);

    summary(groupPoints, groupSize);
    
    std::cout << "Average of given points equals: " << average(groupPoints, groupSize) << "." << std::endl;
    
    std::cout << "Given points: " << std::endl;
    return 0;
}