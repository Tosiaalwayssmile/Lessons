#include <iostream>

#include "userMenu.h"
#include "userLogin.h"
#include "userLogout.h"
#include "userRegister.h"
#include "displayUsers.h"
#include "SQLHandle.h"

void userMenu()
{
	int userChoice = 0;
	int repeatIndicator = 1;
	bool isLoggedIn = false;

	while (repeatIndicator)
	{
		std::cout << "\nAvailable operations: "
			"\n1. Sign in."
			"\n2. Sign up."
			"\n3. Change password."
			"\n4. Delete account."
			"\n5. Sign off."
			"\n6. Exit."
			"\nInsert operation number (1-6): ";
		std::cin >> userChoice;

		switch (userChoice)
		{
			case 1:  //login
			{
				sqlHandler(isLoggedIn, loginUser);
				break;
			}
			case 2:	//register
			{
				sqlHandler(isLoggedIn, registerUser);
				break;
			}
			case 3:	//change password
			{
				std::cout << "\nChanging password..." << std::endl;
				break;
			}
			case 4:	//delete account
			{
				std::cout << "\nDeleting account..." << std::endl;
				break;
			}
			case 5: //logout
			{
				logoutUser(isLoggedIn);
				break;
			}
			default:
			{
				repeatIndicator = 0;
				break;
			}
		}
	}
	std::cout << "\nPress any key to exit...";
}