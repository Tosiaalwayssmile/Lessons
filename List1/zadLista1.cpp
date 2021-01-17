#include <iostream>
#include <ctype.h> //isdigit
#include <sstream> //stringstream
using namespace std;

int main()
{
    /************************************************** ZADANIE 1 ***************************************************/
    /************ POLISH DESCRIPTION: Program przeliczajcy wielkość kąta wyrażoną w stopniach na radiany ************/
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
    cout << "The radian measure of given angle equals: " << degreeAngle*3.14/180 << endl << endl;

    /************************************************** ZADANIE 2 ***************************************************/
    /*************************** POLISH DESCRIPTION: Program obliczający objętość stożka ***************************/

    cout << "Ex.2 Work in progress, thanks for your patience" <<endl;

    return 0;

}