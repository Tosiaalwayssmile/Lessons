#ifndef _SQLHandle_cpp_
#define _SQLHandle_cpp_

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

//void sqlHandler();    
//void sqlHandler(void(*ExampleFunctionPointer)(unsigned int, const SQLHANDLE&, bool&));

void sqlHandler(bool& isLoggedIn, void(*ExampleFunctionPointer)(unsigned int, const SQLHANDLE&, bool&));

//typedef void (*ExampleFunctionPointer)(unsigned int, bool&);
//void sqlHandler(ExampleFunctionPointer);

#endif 
