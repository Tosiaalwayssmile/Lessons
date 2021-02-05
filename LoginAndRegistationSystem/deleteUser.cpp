#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "SQLHandle.h"
#include "userLogin.h"
#include "deleteUser.h"

void deleteUser(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, int& loggedUserID)
{
	char deleteAccount = 'z';

	if (loggedUserID != 0)
	{
		std::cout << "\nDELETE ACCOUNT" << std::endl;

		while (toupper(deleteAccount) != 'Y' && toupper(deleteAccount) != 'N')
		{
			std::cout << "Are you sure you want to delete your account? Y/n: ";
			std::cin >> deleteAccount;

			switch (toupper(deleteAccount))
			{
				case 'Y':
				{
					char SQLQuery[] = "DELETE FROM usersDatabase.dbo.Users WHERE UserID = ?";

					SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, SQL_INTEGER, 0, 0, &loggedUserID, 0, 0);

					SQLExecDirect(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS);
					loggedUserID = 0;
			
					break;
				}
				case 'N':
				{
					break;
				}
				default:
				{
					std::cout << "\nWrong input." << std::endl;
					break;
				}
			}
		}
	}
	else
	{
		std::cout << "You are not signed in." << std::endl;
	}

}