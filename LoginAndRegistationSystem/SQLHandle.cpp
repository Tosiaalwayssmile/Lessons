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

typedef void (*ExampleFunctionPointer)(unsigned int, const SQLHANDLE&, int&);

void sqlHandler(int &loggedUserID, ExampleFunctionPointer myFunction)
{
	/* Define handles and variables*/
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE sqlConnHandle = NULL;
	SQLHANDLE sqlStmtHandle = NULL;
	SQLRETURN retCode = 0;

	#define SQL_RESULT_LEN 240
	#define SQL_RETURN_CODE_LEN 1024	
	
	/* Initialize the ODBC environment handle. */
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle); // Allocates the environment
	
	/* Set the ODBC version to version 3 (the highest version) */
	SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0); // Sets attributes that govern aspects of environments
		
	/* Allocate the connection handle. */
	SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &sqlConnHandle);
	
	/* Set attributes that govern aspects of connections */
	SQLSetConnectAttr(sqlConnHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0);

	/* Conection string */
	SQLWCHAR retConString[SQL_RETURN_CODE_LEN];

	/* Connect to the database using the connection string (not the ODBC DSN definition which is also cool). */
	SQLDriverConnectW(sqlConnHandle, NULL, (SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=usersDatabase;Trusted=true;", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT);
	
	/* Executes SQL-query in function that myFunction is a pointer to */
	myFunction(SQL_HANDLE_STMT, sqlStmtHandle, loggedUserID);
	
	/* Frees the resources and disconnects */
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);

	/* Disconnect from the database. */
	SQLDisconnect(sqlConnHandle);

	/* Free the connection handle. */
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);

	/* Free the environment handle. */
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
}
