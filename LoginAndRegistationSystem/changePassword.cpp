#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "SQLHandle.h"
#include "userLogin.h"
#include "systemSleep.h"
#include "changePassword.h"

void getCurrentPassword(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, int& loggedUserID)
{
	char Password[255] = " ";
	//return Password;
}

void changePassword(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, int &loggedUserID)
{
	if (loggedUserID != 0)
	{
		char inputPassword[255] = " ";

		char Password[255] = " ";sqlHandler(loggedUserID, getCurrentPassword);
		

		bool correctPassword = 0;

		char SQLQuery[] = "UPDATE usersDatabase.dbo.Users SET Password = ? WHERE UserID = ?";
		
		
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, SQL_VARCHAR, sizeof(inputPassword), 0, inputPassword, 0, 0); 
		
		SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, SQL_INTEGER, 0, 0, &loggedUserID, 0, 0);
		std::cout << "Current password: " << Password;
		
		while (!correctPassword)
		{
			std::cout << "Insert new password: ";
			std::cin >> inputPassword;
			if (!strcmp(Password, inputPassword))
			{
				std::cout << "New password must be different than current password." << std::endl;
			}
			else
			{
				correctPassword = 1;
			}
		}
		

		SQLExecDirect(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS);		
	}
	else
	{
		std::cout << "You are not signed in." << std::endl;
	}
}