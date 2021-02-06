       What I learned while doing exercises from this list is:
  * how to get the size of an array:   
    int arrSize = *(&arrayName + 1) - arrayName;
  * and how to make templates for calling the function with differents type parameters
  
        /* CALLING FUNCTION */
  
  displayTable<int>(arrayName, arrSize1); // calling function displayTable with passing int array
  displayTable<float>(arrayName, arrSize1); // calling function displayTable so it takes a float array as a first parameter
  
       /* DECLARATION */
  
  template <typename T> void displayTable(T array[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

        OPIS ZADAŃ / TASK DESCRIPTION IN POLIS

ZADANIE 1. Napisac program umożliwiający obliczenie na podstawie miesięcznych przychodów firmy:

1. Jaki był wynik maksymalny, a jaki minimalny i w ktorym miesiącu.
2. Średniego wyniku firmy.
3. Ile razy firma zanotowala straty i w jakich miesiacach.

ZADANIE 2. Napisac program skladajacy sie z funkcji. W programie zadeklarowac jednowymiarowa tablice N[20] zawierajca liczby calkowite.

1. Tablice wypelnic liczbami losowymi z przedzialu podanego przez uzytkownika.
2. Utworzyc tablice jednowymiarowa B, przepisujac do niej najpierw elementy nieparzyste, a nastepnie elementy parzyste tablicy N.
3. Wyswietlic elementy tablicy na ekranie.
