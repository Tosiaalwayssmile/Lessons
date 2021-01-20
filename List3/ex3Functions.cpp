#include <iostream>
#include <cmath>


int nFactorial (int n); 
int newtonSymbol (int n, int k);
void pascalTriangle (int rows);
int countInputSum(std::string &inputString);
bool checkParity(int sum); 
bool pythagorasNumber(int a,int b,int c);
int greatesCommonDivisor(int a, int b);

std::string inputValidation1(std::string type);

int nFactorial (int n)
{
    int nFactorial = 0;
    if (n < 0) n *= -1;
    if (n == 0) nFactorial = 1;
    else
    {
        nFactorial = n;
        while(n>1)
        {
            nFactorial *= (n-1);
            n--;
        }  
    }
    return nFactorial;
}

int newtonSymbol (int n, int k)
{
    return (nFactorial(n) / (nFactorial(k)* nFactorial(n-k)));
}

void pascalTriangle (int rows)
{
    int value = 1;
    for(int i = 0; i < rows; i++)
    {
        for(int space = 1; space <= rows-i; space++)   // Spaces from the left to the values, with each iterations there's
            std::cout <<"  ";                          // less of them

        for(int j = 0; j <= i; j++)
        {
            if (j == 0 || i == 0)                      // For the 1st and the 2sd row and the first value to the left there is only possible '1' 
                value = 1;
            else
                value = value *(i-j+1)/j;

            std::cout << value << "   ";
        }
        std::cout << std::endl;
    }
}

int countInputSum(std::string &inputString)
{
    int sum = 0;
    std::cout << "Insert numbers separated by space. To fnish press enter: " << std::endl;\

    while(std::cin.get())
    {
        char optionCharacter;
        inputString = inputValidation1("integer");
        sum += stoi(inputString);
        std::cin.ignore(); 
        std::cout << "Press [enter] to see if the sum of given numbers is even: ";
        std::cin.get(optionCharacter);
        if (optionCharacter =='\n') // check to see if hit enter (\n)
        {
            break;
        }
    } 
    std::cout << "suma: " << sum << std::endl;
    return sum;
}

bool checkParity(int sum)
{
    if (sum % 2 == 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

bool pythagorasNumber(int a,int b,int c)
{
    if (pow(a,2) + pow(b,2) == pow(c,2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int greatesCommonDivisor(int a, int b)
{
    int GCD = 0;

    return GCD;
}


std::string inputValidation1(std::string type)
{
    std::string input = "null";
    bool checkFlag = 0;
    while (!checkFlag)
    {
        std::cin >> input;
        if (type == "int" || type == "integer") 
        {
            if (input[0] == '-')
            {
                if (isdigit(input[1]))
                {
                    checkFlag = 1;
                    //std::cout << "Noice, you entered a valid value" << std::endl;
                }
                else
                {
                    std::cout << "Error. Invalid value, re-enter: ";
                    checkFlag = 1;
                    }
            }
            else
            {
                if (isdigit(input[0]))
                {
                    checkFlag = 1;
                    //std::cout << "Noice, you entered a valid value" << std::endl;
                }
                else
                {
                    std::cout << "Error. Invalid value, re-enter: ";
                    }
            }
        }
    }
    return input;
}