#ifndef _userRegister_cpp_
#define _userRegister_cpp_

#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

void registerUser(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, int &loggedUserID);

#endif 
