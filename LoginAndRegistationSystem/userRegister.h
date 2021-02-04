#ifndef _userRegister_cpp_
#define _userRegister_cpp_

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

void registerUser(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, bool isLoggedIn);

#endif 
