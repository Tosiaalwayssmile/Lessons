#include <iostream>

std::string inputValidation(std::string type);

std::string inputValidation(std::string type)
{
    std::string input = "null";
    bool checkFlag = 0;
    while (!checkFlag)
    {
        std::cin >> input;
        if (type == "int" || type == "integer") 
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
        else if (type == "float") 
        {
            if (isdigit(input[0]))
            {
                checkFlag = 1;
                //std::cout << "Good job, you entered a valid value" << std::endl;
            }
            else
            {
                std::cout << "Error. Invalid value, re-enter: " << std::endl;
            }
        }
        else
            std::cout << "Error in code, check function parameter when calling function" << std::endl;
    }
    return input;
}