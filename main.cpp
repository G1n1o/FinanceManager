#include <iostream>
#include "FinanceManager.h"


using namespace std;


int main() {
    FinanceManager financeManager("Users.xml", "Incomes.xml", "Expenses.xml");

    char choice;
    financeManager.showAllUsers();
    while (true) {
        if (!financeManager.isUserLoggedin()) {
            choice = financeManager.selectOptionFromGeneralMenu();

            switch (choice) {
            case '1': financeManager.userRegistration(); break;
            case '2': financeManager.userLogging(); break;
            case '9': exit(0); break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = financeManager.selectOptionFromUserMenu();

            switch (choice) {
            case '1': financeManager.addNewIncome(); break;
            case '2': break;
            case '3': financeManager.displayIncomesForCurrentMonth();
            case '4': break;
            case '5': break;
            case '6': financeManager.changePasswordLoggedUser();break;
            case '7': financeManager.userLogout(); break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}


