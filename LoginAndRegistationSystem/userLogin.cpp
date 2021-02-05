#include <iostream>
#include "SQLHandle.h"
#include "userLogin.h"
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include "systemSleep.h"

void loginUser(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, int &loggedUserID)
{
	if (!loggedUserID)
	{
		char SQLQuery[] = "SELECT * FROM Users"; 
		SQLExecDirect(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS);
		
		char inputLastName[255] = "";
		char inputPassword[255] = "";

		int UserID = 0;
		char LastName[255] = "";
		char FirstName[255] = "";
		char Password[255] = "";

		std::cout << "\nSIGN IN" << std::endl;

		std::cout << "Insert your last name: ";
		std::cin >> inputLastName;

		std::cout << "Insert your password: ";
		std::cin >> inputPassword;

		bool isInDatabase = 0;

		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			// if true strcmp returns 0 so if (both strings are equal (!0 == 1)) 
			if (!strcmp(LastName, inputLastName) && !strcmp(Password, inputPassword))
			{
				isInDatabase = 1;
				break;
			}
			// Fetches the next rowset of data from the result
			SQLGetData(sqlStmtHandle, 1, SQL_C_DEFAULT, &UserID, sizeof(UserID), NULL);
			SQLGetData(sqlStmtHandle, 2, SQL_C_DEFAULT, &LastName, sizeof(LastName), NULL);
			SQLGetData(sqlStmtHandle, 3, SQL_C_DEFAULT, &FirstName, sizeof(FirstName), NULL);
			SQLGetData(sqlStmtHandle, 4, SQL_C_DEFAULT, &Password, sizeof(Password), NULL);
			// Retrieves data for a single column in the result set

		}
		if (isInDatabase)
		{
			sleep();
			std::cout << "You are signed in." << std::endl;
			sleep();
			std::cout << "Info from database: " << "UserID: " << UserID << ", Last name: " << LastName
				<< ", First name: " << FirstName  << std::endl; //<< ", Password: " << Password
			loggedUserID = UserID;
		}
		else if (!isInDatabase)
		{
			sleep();
			std::cout << "Wrong input. No such data." << std::endl;
		}
	}
	else
	{
		std::cout << "You are alredy signed in." << std::endl;
	}
}