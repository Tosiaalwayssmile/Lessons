#include <iostream>

#include "systemSleep.h"
#include "userMenu.h"

// TO DO
// hashbytes - encrypt password
// increment UserId so new users have userID +1

// function for creating database (if not exists)

//na gicie doda� readme i gitignore w ka�dym projekcie
//zrobi� test cpp i updateowa� CV
// wys�a� je na te og�oszenia

int main()
{
	std::cout << "Welcome to my login and registration system." << std::endl;
	sleep();
	userMenu();
	return 0;
}



