#include <iostream>
#include "FinanceManager.h"


using namespace std;


int main() {
    FinanceManager financeManager("Users.xml");
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
            financeManager.changePasswordLoggedUser();
            break;
        }
    }
    return 0;
}


