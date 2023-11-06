#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "Accountant.h"


class FinanceManager {
    UserManager userManager;
    Accountant *accountant;
    const std::string FILE_NAME_WITH_INCOMES;
    const std::string FILE_NAME_WITH_EXPENSES;

public:
    FinanceManager(std::string fileNameWithUsers, std::string fileNameWithIncomes, std::string fileNameWithExpenses)
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
    void addNewIncome();
    void addNewExpense();
    void showUserIncomes();
    void displayBalanceForCurrentMonth();
    void displayBalanceForPreviousMonth();
    void displayBalanceInDateRange();


};
#endif
