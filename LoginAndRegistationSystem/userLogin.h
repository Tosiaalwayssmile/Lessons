#ifndef _userLogin_cpp_
#define _userLogin_cpp_

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

void loginUser(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, bool& isLoggedIn);
void function(unsigned int handleType, bool& isLoggedIn);

#endif 