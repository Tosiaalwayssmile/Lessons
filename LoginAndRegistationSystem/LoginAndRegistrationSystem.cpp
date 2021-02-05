#include <iostream>
#include "SQLHandle.h"
#include "systemSleep.h"
#include "userMenu.h"

// TO DO


// hashbytes - encrypt password
// increment UserId so new users have userID +1

// function for creating database (if not exists)
//posprzatac w kodzie + dodac komentarze
//na gicie dodaæ readme i gitignore w ka¿dym projekcie
//zrobiæ test cpp i updateowaæ CV
// wys³aæ je na te og³oszenia

int main()
{
	std::cout << "Welcome to my login and registration system." << std::endl;

	sleep();
	
	//createTable();

	userMenu();
	return 0;
}



