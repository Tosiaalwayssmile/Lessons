#ifndef _CHANGE_PASSWORD_cpp_
#define _CHANGE_PASSWORD_cpp_

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

void changePassword(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, int &loggedUserID);

#endif 
