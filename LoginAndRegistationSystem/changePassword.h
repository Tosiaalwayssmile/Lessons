#ifndef _changePassword_cpp_
#define _changePassword_cpp_

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

void changePassword(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, int &loggedUserID);

#endif 
