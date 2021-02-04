#include <iostream>
#include "SQLHandle.h"
#include "displayUsers.h"
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

void displayAllUsers(unsigned int handleType, const SQLHANDLE& sqlStmtHandle)
{
	int UserID = 0;
	char LastName[255] = "";
	char FirstName[255] = "";
	char Password[255] = "";

	char SQLQuery[] = "SELECT * FROM usersDatabase.dbo.Users";

	SQLExecDirect(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS);

	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		// Fetches the next rowset of data from the result
		SQLGetData(sqlStmtHandle, 1, SQL_C_DEFAULT, &UserID, sizeof(UserID), NULL);
		SQLGetData(sqlStmtHandle, 2, SQL_C_DEFAULT, &LastName, sizeof(LastName), NULL);
		SQLGetData(sqlStmtHandle, 3, SQL_C_DEFAULT, &FirstName, sizeof(FirstName), NULL);
		SQLGetData(sqlStmtHandle, 4, SQL_C_DEFAULT, &Password, sizeof(Password), NULL);

		// Retrieves data for a single column in the result set
		std::cout << "User: " << "UserID: " << UserID << ", Last name: " << LastName
			<< ", First name: " << FirstName << ", Password: " << Password << std::endl;
	}
}