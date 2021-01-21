#include <iostream>
#include <cmath>

using namespace std;

int main()
{  
    /********************************************************* ZADANIE 1 **********************************************************/
    /******************* POLISH DESCRIPTION: Program przeliczajcy wielkość kąta wyrażoną w stopniach na radiany *******************/
    /*  Formula for converting degrees to radians:
        n(degrees) = n*pi/180 
    */
    cout << "Ex.1 Program converting angles from degrees to radians" << endl; 
    string degreeAngleString = "";
    bool notNumberBool = true;
    float degreeAngle = 0;

    while(notNumberBool)
    {
        cout << "Insert angle in degrees: ______\b\b\b\b\b\b"; 
        cin >> degreeAngleString;

        if( degreeAngleString.find_first_not_of("1234567890.-") != string::npos ) 
        {
            cout << "invalid number: " << degreeAngleString << endl;
        } 

        else 
        {
            degreeAngle = stof(degreeAngleString);
            notNumberBool = false;
        }
    }  
    cout << "The radian measure of given angle equals: " << degreeAngle * 3.14 / 180 << endl << endl;  

    /********************************************************* ZADANIE 2 **********************************************************/
    /********************************** POLISH DESCRIPTION: Program obliczający objętość stożka ***********************************/

    cout << "Ex.2 Program finding the volume of a cone" << endl;
    float H = 0; // height of a cone
    float r = 0; // radius of a cone

    cout << "Insert the height of a cone: ______\b\b\b\b\b\b";
    cin >> H;

    cout << "Insert the radius of a cone: ______\b\b\b\b\b\b";
    cin >> r;

    cout << "The volume of a cone equals: " << r * r * H * 3.14 / 3 << endl << endl;

    /********************************************************* ZADANIE 3 **********************************************************/
    /** POLISH DESCRIPTION: Program obliczający średnią arytmetyczną, sumę odwrotności i sprawdzający, czy suma jest nieparzysta **/

    cout << "Ex.3 Count arithmetic average, reciprocal sum and check if sum is odd" << endl;
    int a = 0, b = 0, c = 0;
    string parity = "odd";

    cout << "Insert the first integer number: ______\b\b\b\b\b\b";
    cin >> a;

    cout << "Insert the second integer number: ______\b\b\b\b\b\b";
    cin >> b;

    cout << "Insert the third integer number: ______\b\b\b\b\b\b";
    cin >> c;

    cout << "\nThe arithemtic average equals: " << (a + b + c) / 3. << endl;  // 3. so the fractional part is not discarded
    cout << "The reciprocal sum equals: " << 1./a + 1./b + 1./c << endl;

    if ((a + b + c) % 2 == 0)
        parity = "even";
    cout << "The sum is " << parity << "." << endl;

    /********************************************************* ZADANIE 4 **********************************************************/
    /************************************* POLISH DESCRIPTION: Program rozwiązujący równanie kwadratowe****************************/

    a = 0, b = 0, c = 0;
    cout << "\nEx.4 Solve quadratic equation: a^2 + bx + c = 0 or linear equation bx + c = 0" << endl;

    cout << "Insert a: ______\b\b\b\b\b\b";
    cin >> a;

    cout << "Insert b: ______\b\b\b\b\b\b";
    cin >> b;

    cout << "Insert c: ______\b\b\b\b\b\b";
    cin >> c;

    float root0 = 0, root1 = 0, root2 = 0;
    
    if (a != 0)
    {
        float delta = b * b - (4 * a * c);
        if (delta > 0 )
        {
            root1 = (-b + sqrt(delta)) / (2 * a);
            root2 = (-b - sqrt(delta)) / (2 * a);
            cout << "The roots of quadratic equation are: " << root1 << " and " << root2 << endl;
        }
        else if (delta == 0)
        {
            root1 = (-b) / (2 * a);
            cout << "The double root of quadratic equation is: " << root1 << endl;
        }
        else
        {
            cout << "There are no roots of given equation." << endl;
        }
    }
    else 
    {
        float root0 = -c / b;
        cout << "The root of linear equation is: " << root0 << endl;
    }
    return 0;
}