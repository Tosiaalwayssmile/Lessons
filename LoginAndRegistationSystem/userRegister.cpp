#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "SQLHandle.h"
#include "userRegister.h"

void registerUser(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, bool isLoggedIn)
{
	if (isLoggedIn == false)
	{
		SQLVARCHAR inputLastName[255];
		SQLVARCHAR inputFirstName[255];
		SQLVARCHAR inputPassword[255];
		SQLINTEGER LastName = SQL_NTS, FirstName = SQL_NTS, Password = SQL_NTS;
		SQLINTEGER inputUserID, UserID = 0;
		
		char SQLQuery[] = "INSERT INTO usersDatabase.dbo.Users (UserID, LastName, FirstName, Password) VALUES (?,?,?,?);";

		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, SQL_INTEGER, 0, 0, &inputUserID, 0, &UserID);
		SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, SQL_VARCHAR, sizeof(inputLastName), 0, inputLastName, 0, &LastName);
		SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_DEFAULT, SQL_VARCHAR, sizeof(inputFirstName), 0, inputFirstName, 0, &FirstName);
		SQLBindParameter(sqlStmtHandle, 4, SQL_PARAM_INPUT, SQL_C_DEFAULT, SQL_VARCHAR, sizeof(inputPassword), 0, inputPassword, 0, &Password);

		std::cout << "\nSIGN UP" << std::endl;

		std::cout << "Insert your last name : ";
		std::cin >> inputLastName;

		std::cout << "Insert your first name : ";
		std::cin >> inputFirstName;

		std::cout << "Insert password : ";
		std::cin >> inputPassword;

		inputUserID = 60;
		//std::cout << "You account info: " << "UserID: " << inputUserID << ", Last name: " << inputLastName
		//	<< ", First name: " << inputFirstName << ", Password: " << inputPassword << std::endl;

		SQLExecDirect(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS);
	}
	else
	{
		std::cout << "\nYou already have an account. Sign off." << std::endl;
	}
}