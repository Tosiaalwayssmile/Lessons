#include <iostream>

#include "userMenu.h"
#include "userLogin.h"
#include "userLogout.h"
#include "userRegister.h"
#include "displayUsers.h"
#include "SQLHandle.h"
#include "changePassword.h"

void userMenu()
{
	int userChoice = 0;
	int repeatIndicator = 1;
	int loggedUserID = 0;

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
				sqlHandler(loggedUserID, loginUser);
				break;
			}
			case 2:	//register
			{
				sqlHandler(loggedUserID, registerUser);
				break;
			}
			case 3:	//change password
			{
				std::cout << "\nChanging password..." << std::endl;
				sqlHandler(loggedUserID, changePassword);
				break;
			}
			case 4:	//delete account
			{
				std::cout << "\nDeleting account..." << std::endl;
				break;
			}
			case 5: //logout
			{
				logoutUser(loggedUserID);
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