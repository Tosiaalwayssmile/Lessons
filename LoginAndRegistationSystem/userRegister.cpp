#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "SQLHandle.h"
#include "userRegister.h"


void registerUser(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, User* loggedUser)
{
	/* Check if user is currently logged in. */
	if (!loggedUser->isLoggedIn)
	{
		SQLINTEGER LastName = SQL_NTS, FirstName = SQL_NTS, Password = SQL_NTS;
		//SQLINTEGER  UserID = 0;
		//sSQLINTEGER inputUserID;

		char SQLQuery[] = "INSERT INTO usersDatabase.dbo.Users (LastName, FirstName, Password) VALUES (?,?,?);";
		
		/* Binding parameters to a query so that the data is sent as a parameter along with the query. */
		//SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, SQL_INTEGER, 0, 0, &inputUserID, 0, &UserID);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, SQL_VARCHAR, sizeof(loggedUser->LastName), 0, loggedUser->LastName, 0, &LastName);
		SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, SQL_VARCHAR, sizeof(loggedUser->FirstName), 0, loggedUser->FirstName, 0, &FirstName);
		SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, SQL_VARCHAR, sizeof(loggedUser->Password), 0, loggedUser->Password, 0, &Password);

		std::cout << "\nSIGN UP" << std::endl;

		std::cout << "Insert your last name : ";
		std::cin >> loggedUser->LastName;

		std::cout << "Insert your first name : ";
		std::cin >> loggedUser->FirstName;

		std::cout << "Insert password : ";
		std::cin >> loggedUser->Password;

		std::cout << "You account info: " << " Last name: " << loggedUser->LastName
			<< ", First name: " << loggedUser->FirstName << ", Password: " << loggedUser->Password << std::endl;

		SQLExecDirect(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS);
	}
	else
	{
		std::cout << "\nYou already have an account. Sign off." << std::endl;
	}
}