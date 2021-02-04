#include <iostream>
#include "SQLHandle.h"
//nclude "SQLHandleRegister.h"
#include "systemSleep.h"
#include "userMenu.h"

// TO DO
// feature: change password????
// feature: delete account

// hashbytes - encrypt password
// increment UserId

// function for creating database (if not exists)
//posprzatac w kodzie + dodac komentarze

int main()
{
	std::cout << "Welcome to my login and registration system." << std::endl;
	sleep();
	//sqlHandler();
	userMenu();
	return 0;
}



