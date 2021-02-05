#ifndef _SQLHandle_cpp_
#define _SQLHandle_cpp_

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

void sqlHandler(int &loggedUserID, void(*ExampleFunctionPointer)(unsigned int, const SQLHANDLE&, int&));

//typedef void (*ExampleFunctionPointer)(unsigned int, bool&);
//void sqlHandler(ExampleFunctionPointer);

#endif 
