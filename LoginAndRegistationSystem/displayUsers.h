#ifndef _displayUsers_cpp_
#define _displayUsers_cpp_

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

void displayAllUsers(unsigned int handleType, const SQLHANDLE& sqlStmtHandle);

#endif 
