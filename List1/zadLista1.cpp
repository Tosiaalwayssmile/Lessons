#include <iostream>
#include <cmath>

int main()
{  
    /********************************************************* ZADANIE 1 **********************************************************/
    /******************* POLISH DESCRIPTION: Program przeliczajcy wielkość kąta wyrażoną w stopniach na radiany. *******************/
    /*  Formula for converting degrees to radians:
        n(degrees) = n*pi/180       */

    std::cout << "Ex.1 Program converting angles from degrees to radians." << std::endl; 
    
    std::string degreeAngleString = "";
    bool notNumberBool = true;
    float degreeAngle = 0;

    while(notNumberBool)
    {
        std::cout << "Insert angle in degrees: ______\b\b\b\b\b\b"; 
        std::cin >> degreeAngleString;

        if( degreeAngleString.find_first_not_of("1234567890.-") != std::string::npos ) 
        {
            std::cout << "invalid number: " << degreeAngleString << std::endl;
        } 

        else 
        {
            degreeAngle = stof(degreeAngleString);
            notNumberBool = false;
        }
    }  
    std::cout << "The radian measure of given angle equals: " << degreeAngle * 3.14 / 180 << "." << std::endl << std::endl;  

    /********************************************************* ZADANIE 2 **********************************************************/
    /********************************** POLISH DESCRIPTION: Program obliczający objętość stożka ***********************************/

    std::cout << "Ex.2 Program finding the volume of a cone." << std::endl;
    float H = 0; // height of a cone
    float r = 0; // radius of a cone

    std::cout << "Insert the height of a cone: ______\b\b\b\b\b\b";
    std::cin >> H;

    std::cout << "Insert the radius of a cone: ______\b\b\b\b\b\b";
    std::cin >> r;

    std::cout << "The volume of a cone equals: " << r * r * H * 3.14 / 3 << "." << std::endl << std::endl;

    /********************************************************* ZADANIE 3 **********************************************************/
    /** POLISH DESCRIPTION: Program obliczający średnią arytmetyczną, sumę odwrotności i sprawdzający, czy suma jest nieparzysta **/

    std::cout << "Ex.3 Count arithmetic average, reciprocal sum and check if sum is odd." << std::endl;
    int a = 0, b = 0, c = 0;
    std::string parity = "odd";

    std::cout << "Insert the first integer number: ______\b\b\b\b\b\b";
    std::cin >> a;

    std::cout << "Insert the second integer number: ______\b\b\b\b\b\b";
    std::cin >> b;

    std::cout << "Insert the third integer number: ______\b\b\b\b\b\b";
    std::cin >> c;

    std::cout << "\nThe arithemtic average equals: " << (a + b + c) / 3. << "." << std::endl;  // 3. so the fractional part is not discarded
    std::cout << "The reciprocal sum equals: " << 1./a + 1./b + 1./c << "." << std::endl;

    if ((a + b + c) % 2 == 0)
    {
        parity = "even";
    }
    std::cout << "The sum is " << parity << "." << std::endl;

    /********************************************************* ZADANIE 4 **********************************************************/
    /************************************* POLISH DESCRI
     * lPTION: Program rozwiązujący równanie kwadratowe****************************/

    a = 0, b = 0, c = 0;
    std::cout << "\nEx.4 Solve quadratic equation: a^2 + bx + c = 0 or linear equation bx + c = 0." << std::endl;

    std::cout << "Insert a: ______\b\b\b\b\b\b";
    std::cin >> a;

    std::cout << "Insert b: ______\b\b\b\b\b\b";
    std::cin >> b;

    std::cout << "Insert c: ______\b\b\b\b\b\b";
    std::cin >> c;

    float root0 = 0, root1 = 0, root2 = 0;
    
    if (a != 0)
    {
        float delta = b * b - (4 * a * c);
        if (delta > 0 )
        {
            root1 = (-b + sqrt(delta)) / (2 * a);
            root2 = (-b - sqrt(delta)) / (2 * a);
            std::cout << "The roots of quadratic equation are: " << root1 << " and " << root2 << "." << std::endl;
        }
        else if (delta == 0)
        {
            root1 = (-b) / (2 * a);
            std::cout << "The double root of quadratic equation is: " << root1 << std::endl;
        }
        else
        {
            std::cout << "There are no roots of given equation." << std::endl;
        }
    }
    else 
    {
        float root0 = -c / b;
        std::cout << "The root of linear equation is: " << root0 << std::endl;
    }
    return 0;
}