#include <iostream>
#include "FinanceManager.h"


using namespace std;


int main()
{
/*
CMarkup users;
users.AddElem( "USERS" );
users.IntoElem();
users.AddElem( "USER" );
users.IntoElem();
users.AddElem( "IDUSER", user.idUser +1 );
users.AddElem( "LOGIN", user.login );
users.AddElem("PASSWORD", user.password);
users.AddElem ("NAME", user.name);
users.AddElem( "SURNAME", user.surname );

users.Save( "users.xml" );
*/
FinanceManager financeManager("Users.xml");
financeManager.showAllUsers();
financeManager.userRegistration();
financeManager.showAllUsers();


return 0;
}
