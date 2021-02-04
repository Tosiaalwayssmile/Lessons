#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "userLogin.h"
#include "userLogout.h"
#include "userRegister.h"
#include "displayUsers.h"
#include "userMenu.h"
#include "SQLHandle.h"

void showSQLError(unsigned int handleType, const SQLHANDLE& handle); 

//typedef void (*ExampleFunctionPointer)(unsigned int, const SQLHANDLE&, bool&);

void sqlHandler(bool &isLoggedIn, void(*ExampleFunctionPointer)(unsigned int, const SQLHANDLE&, bool&))
{
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE sqlConnHandle = NULL;
	SQLHANDLE sqlStmtHandle = NULL;
	SQLRETURN retCode = 0;

	#define SQL_RESULT_LEN 240
	#define SQL_RETURN_CODE_LEN 2000	// 1000
	//define handles and variables

	do {
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
			// Allocates the environment
			goto COMPLETED;

		if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
			// Sets attributes that govern aspects of environments
			goto COMPLETED;

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &sqlConnHandle))
			// Allocates the connection
			goto COMPLETED;

		if (SQL_SUCCESS != SQLSetConnectAttr(sqlConnHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
			// Sets attributes that govern aspects of connections
			goto COMPLETED;

		/*
		std::cout << "Attempting connection to SQL Server...";
		std::cout << "\n";
		*/

		//SQLCHAR retConString[1024]; // Conection string
		SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];

		switch (SQLDriverConnectW(sqlConnHandle, NULL, (SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=master;Trusted=true;",//UID=DESKTOP-02A9CVR\tosia;"PWD=PassWord;
			//(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=master;Trusted=true;",
			SQL_NTS, retconstring, 1024, NULL, SQL_DRIVER_NOPROMPT)) 
		{
			case SQL_SUCCESS:
			{
				//std::cout << "Successfully connected to SQL Server" << std::endl;
								//std::cout << "\n";
				break;
			}	
			case SQL_SUCCESS_WITH_INFO:
			{
				//std::cout << "Successfully connected to SQL Server" << std::endl;
				break;
			}
			case SQL_INVALID_HANDLE:
			{
				//std::cout << "Could not connect to SQL Server" << std::endl;
				goto COMPLETED;
			}
			case SQL_ERROR:
			{
				//std::cout << "Could not connect to SQL Server" << std::endl;
				goto COMPLETED;
			}	
			default:
			{
				break;
			}
		}

		//if (retCode == -1)
			//break;

		//if there is a problem connecting then exit application
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
		{
			goto COMPLETED;		// Allocates the statement
		}	
		
		//output
		//std::cout << "\nExecuting T-SQL query..." << std::endl;

		ExampleFunctionPointer(SQL_HANDLE_STMT, sqlStmtHandle, isLoggedIn);

		goto COMPLETED;

	} while (FALSE);

	// Frees the resources and disconnects
	COMPLETED:
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
}

void showSQLError(unsigned int handleType, const SQLHANDLE& handle)
{
	SQLCHAR SQLState[1024];
	SQLCHAR message[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL))
		// Returns the current values of multiple fields of a diagnostic record that contains error, warning, and status information
		std::cout << "SQL driver message: " << message << "\nSQL state: " << SQLState << "." << std::endl;
}