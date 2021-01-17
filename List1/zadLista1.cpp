#include <iostream>

using namespace std;

int main()
{
    /********************************************************* ZADANIE 1 **********************************************************/
    /******************* POLISH DESCRIPTION: Program przeliczajcy wielkość kąta wyrażoną w stopniach na radiany *******************/
    /*
        Formula for converting degrees to radians:
        n(degrees) = n*pi/180 
    */
    cout << "Ex.1 Program converting angles from degrees to radians" << endl; 
    string degreeAngleString = "";
    bool notNumberBool = true;
    float degreeAngle = 0;
    while(notNumberBool)
    {
        cout << "Insert angle in degrees: "; 
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
    cout << "The radian measure of given angle equals: " << degreeAngle*3.14/180 << endl;

    /********************************************************* ZADANIE 2 **********************************************************/
    /********************************** POLISH DESCRIPTION: Program obliczający objętość stożka ***********************************/

    cout << "\nEx.2 Program finding the volume of a cone" <<endl;
    float H = 0; // height of a cone
    float r = 0; // radius of a cone
    cout << "Insert the height of a cone: ";
    cin >> H;
    cout << "Insert the radius of a cone: ";
    cin >> r;
    cout << "The volume of a cone equals: " << r*r*H*3.14/3;

    /********************************************************* ZADANIE 3 **********************************************************/
    /** POLISH DESCRIPTION: Program obliczający średnią arytmetyczną, sumę odwrotności i sprawdzający, czy suma jest nieparzysta **/

    cout << "\nEx.3 Work in progress, thanks for your patience" <<endl;

    return 0;

}