#ifndef _deleteUsers_cpp_
#define _deleteUsers_cpp_

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

void deleteUser(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, int& loggedUserID);

#endif 
