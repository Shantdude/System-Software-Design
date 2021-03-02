

#include"sql.h"

#include"sqlext.h"

#include"string.h"

#include"stdio.h"

struct student

{

	int roll;

	char name[10];

	char branch[20];

};



main()

{

	SQLHENV p;//p,q,r are generic pointers here

	SQLHDBC q;

	SQLHSTMT r;

	

	

	

	SQLAllocHandle(SQL_HANDLE_ENV,0,&p);//handle,child,&parent

		SQLSetEnvAttr(p,SQL_ATTR_ODBC_VERSION,SQL_OV_ODBC3,0);

	SQLAllocHandle(SQL_HANDLE_DBC,p,&q);//handle,child,&parent

	SQLAllocHandle(SQL_HANDLE_STMT,q,&r);//handle,child,&parent

	

	SQLConnect(q,"collage",strlen("collage"),"root",strlen("root"),"",strlen(""));//connection handle,"connection string",length of string, "user name", strlen(user),"password", 		//																				strlen("password")

	

	char x[]="use collage";//MYSQL commands

	SQLPrepare(r,x,strlen(x));

	char y[]="insert into student values(?,?,?)";//insert data in "?"

	SQLPrepare(r,y,strlen(y));

	

	SQLBindParameter(r,1,SQL_PARAM_INPUT,SQL_INTEGER,SQL_C_LONG,4,0,&m.roll,sizeof(m.roll),0);

		SQLBindParameter(r,2,SQL_PARAM_INPUT,SQL_CHAR,SQL_C_CHAR,4,0,m.name,strlen(m.name),0);

			SQLBindParameter(r,3,SQL_PARAM_INPUT,SQL_INTEGER,SQL_C_LONG,4,0,&m.roll,sizeof(m.roll),0);

	

	SQLExecute(r);//execute sql

	

	

	SQLFreeHandle(SQL_HANDLE_STMT,r);//free handle memory

	SQLFreeHandle(SQL_HANDLE_DBC,q);

	SQLFreeHandle(SQL_HANDLE_ENV,p);

	

	

	SQLDisconnect(q);//disconnect database
}