#include <iostream>
#include "FinanceManager.h"



int main() {
    FinanceManager financeManager("Users.xml", "Incomes.xml", "Expenses.xml");

    char choice;
     while (true) {
        if (!financeManager.isUserLoggedin()) {
            choice = financeManager.selectOptionFromGeneralMenu();

            switch (choice) {
            case '1': financeManager.userRegistration(); break;
            case '2': financeManager.userLogging(); break;
            case '9': exit(0); break;
            default:
                std::cout << std::endl << "Nie ma takiej opcji w menu." << std::endl << std::endl;
                system("pause");
                break;
            }
        } else {
            choice = financeManager.selectOptionFromUserMenu();

            switch (choice) {
            case '1': financeManager.addNewIncome(); break;
            case '2': financeManager.addNewExpense(); break;
            case '3': financeManager.displayBalanceForCurrentMonth(); break;
            case '4': financeManager.displayBalanceForPreviousMonth(); break;
            case '5': financeManager.displayBalanceInDateRange();break;
            case '6': financeManager.changePasswordLoggedUser(); break;
            case '7': financeManager.userLogout(); break;
            default:
                std::cout << std::endl << "Nie ma takiej opcji w menu." << std::endl << std::endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}


