#include <iostream>
#include "SQLHandle.h"
#include "systemSleep.h"
#include "userMenu.h"

// TO DO


// hashbytes - encrypt password
// increment UserId so new users have userID +1

// function for creating database (if not exists)
//posprzatac w kodzie + dodac komentarze
//na gicie doda� readme i gitignore w ka�dym projekcie
//zrobi� test cpp i updateowa� CV
// wys�a� je na te og�oszenia

int main()
{
	std::cout << "Welcome to my login and registration system." << std::endl;

	sleep();
	
	//createTable();

	userMenu();
	return 0;
}



