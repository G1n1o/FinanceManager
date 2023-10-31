#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "Accountant.h"

using namespace std;

class FinanceManager {
    UserManager userManager;
    Accountant *accountant;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

public:
    FinanceManager(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses) {
        accountant = NULL;
    };
    ~FinanceManager() {
        delete accountant;
        accountant = NULL;
    }

    void userRegistration();
    void showAllUsers();
    void userLogging();
    void userLogout();
    void changePasswordLoggedUser();
    char selectOptionFromGeneralMenu();
    char selectOptionFromUserMenu();
    bool isUserLoggedin();


};
#endif
