#include <iostream>

#include "userMenu.h"
#include "userLogin.h"
#include "userLogout.h"
#include "userRegister.h"
#include "displayUsers.h"
#include "SQLHandle.h"
#include "changePassword.h"
#include "deleteUser.h"
#include "refreshID.h"

void userMenu()
{
	int userChoice = 0;
	int repeatIndicator = 1;
	User loggedUser;
	loggedUser.isLoggedIn = 0;

	/* Function displaying all users that are currently in database, you can uncomment this for testing. */
	//sqlHandler(&loggedUser, displayAllUsers);

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
				sqlHandler(&loggedUser, loginUser);
				break;
			}
			case 2:	//register
			{
				sqlHandler(&loggedUser, registerUser);
				sqlHandler(&loggedUser, refreshID);
				break;
			}
			case 3:	//change password
			{
				sqlHandler(&loggedUser, changePassword);
				break;
			}
			case 4:	//delete account
			{
				sqlHandler(&loggedUser, deleteUser);
				break;
			}
			case 5: //logout
			{
				logoutUser(&loggedUser);
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