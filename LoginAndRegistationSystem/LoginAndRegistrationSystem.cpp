#include <iostream>
#include "SQLHandle.h"
#include "systemSleep.h"
#include "userMenu.h"

// TO DO
// get loggedUserId without passing variable so much

// feature: delete account

// hashbytes - encrypt password
// increment UserId

// function for creating database (if not exists)
//posprzatac w kodzie + dodac komentarze

int main()
{
	std::cout << "Welcome to my login and registration system." << std::endl;

	sleep();
	
	//createTable();

	userMenu();
	return 0;
}



