#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <ctype.h> // toupper

#include "SQLHandle.h"
#include "userLogout.h"
#include "systemSleep.h"

void logoutUser(bool &isLoggedIn)
{
	char signOff = 'z';

	if (isLoggedIn == true)
	{
		std::cout << "\nSIGN OFF" << std::endl;

		while (toupper(signOff) != 'Y' && toupper(signOff) != 'N')
		{
			std::cout << "Are you sure you want to sign off? Y/n: ";
			std::cin >> signOff;

			switch (toupper(signOff))
			{
				case 'Y':
				{
					isLoggedIn = false;
					sleep();
					std::cout << "\nYou successfully signed off." << std::endl;
					break;
				}
				case 'N':
				{
					break;
				}
				default:
				{
					std::cout << "\nWrong input." << std::endl;
					break;
				}
			}
		}
	}
	else
	{
		std::cout << "You are not signed in." << std::endl;
	}
}