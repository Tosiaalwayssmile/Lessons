#include <iostream>
using namespace std;

int main()
{
    float katS = 0;
    int katR = 0;
    cout << "Program przeliczajcy wielkość kąta wyrażoną w stopniach na radiany" << endl; 
    /*
        Wzór na zamianę stopni na radiany to:
        n(stopni) = n*pi/180 
    */
    cout << "Podaj wielkość kąta w stopniach: "; 
    cin >> katS;
    katR = katS*3,14/180;
    cout << "\nWielkość podanego kąta w radianach wynosi: " << endl;
    return 0;

}