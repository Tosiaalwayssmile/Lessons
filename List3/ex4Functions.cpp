#include <iostream>

int countInputSum(std::string &inputString);
bool checkParity(int sum); 
std::string inputValidation1(std::string type);

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