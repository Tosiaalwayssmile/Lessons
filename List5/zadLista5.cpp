//int *wsk = nullptr;
#include <iostream>
#include "ex1Functions.cpp"

#define groupSize 100
#define pointsRange 11

int main()
{
    /* ******************************** ZADANIE *****************************************
    Grupę 100 osób poproszono o ocenę filmu. Każdy mógł przyznać punkty od 0 do 10.
    1. Zadeklarować tablicę 100-elementową.
    2. Wylosować elementy tej tablicy z przedziału <0, 10>.
    3. Podsumować wyniki głosowania tzn. obliczyć ile osób przyznało 0 punktów, 1 punkt, 2 punkty itp.
    4. Obliczyć średnią liczbę punktów.
    5. Obliczyć medianę (środkowa wartość w posortowanej tablicy, w przypadku parzystej
    liczby elementów tablicy jest to średnia dwóch środkowych wartości).
    6. Obliczyć dominantę (najczęściej występującą wartość, w przypadku kilku
    jednakowych wartości podać wszystkie) .
    7. Narysować histogram złożony z #. Histogram pokazuje liczebności poszczególnych
    grup.
    Program podzielić na funkcje. Rozmiar tablicy ustalić za pomocą dyrektywy definiującej. */

    std::cout << "*******************************************************************" 
                 "\nEx.1 Group of people rated a movie from 0-10." 
                 "\n******************************************************************" << std::endl;

    int groupPoints[groupSize];

    srand(time(NULL));
    fillIn(0, 10, groupPoints, groupSize);

    //displayTable<int>(groupPoints, groupSize);        // Display to see unsorted table

    int summaryPoints[pointsRange] = {0};
    summary(groupPoints, groupSize, summaryPoints);
    
    std::cout << "Average of given points equals: " << average(groupPoints, groupSize) << "." << std::endl;
    
    std::cout << "Median of given points equals: " << median(groupPoints, groupSize) << "." << std::endl;
    
    //displayTable<int>(groupPoints, groupSize);        //Display to see sorted table (function median calls sort function)

    mode(summaryPoints, pointsRange);    //mode in polish means dominanta

    std::cout << "\n    Histogram";
    histogram(summaryPoints, pointsRange);
    
    std::cout << "\nThanks for stopping by :)" << std::endl;
    return 0;
}