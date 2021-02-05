#ifndef _SQLHandle_cpp_
#define _SQLHandle_cpp_

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

typedef void (*ExampleFunctionPointer)(unsigned int, const SQLHANDLE&, int&);
void sqlHandler(int&, ExampleFunctionPointer ex);

#endif 
