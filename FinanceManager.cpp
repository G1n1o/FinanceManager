#include "FinanceManager.h"

void FinanceManager::userRegistration() {
    userManager.userRegistration();
}

void FinanceManager::showAllUsers() {
    userManager.showAllUsers();
}

void FinanceManager::userLogging() {
    userManager.userLogging();
    if (userManager.isUserLoggedIn()) {
        accountant = new Accountant(FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES,userManager.getidLoggedUser());
    }
}

void FinanceManager::changePasswordLoggedUser() {
    if (userManager.isUserLoggedIn()) {
        userManager.changePasswordLoggedUser();
    } else {
        std::cout << "Aby zmienic haslo, nalezy sie najpierw zalogowac" << std::endl;
        system("pause");
    }
}

bool FinanceManager::isUserLoggedin() {
    return userManager.isUserLoggedIn();
}
void FinanceManager::userLogout() {
    userManager.userLogout();
    delete accountant;
    accountant = NULL;
}

char FinanceManager::selectOptionFromGeneralMenu() {
    char choice;

    system("cls");
    std::cout << "    >>> MENU  GLOWNE <<<" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "1. Rejestracja" << std::endl;
    std::cout << "2. Logowanie" << std::endl;
    std::cout << "9. Koniec programu" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Twoj wybor: ";
    choice = SupportiveMethods::readSign();
    return choice;
}

char FinanceManager::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    std::cout << " >>> MENU UZYTKOWNIKA <<<" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "1. Dodaj przychod" << std::endl;
    std::cout << "2. Dodaj wydatek" << std::endl;
    std::cout << "3. Bilans z biezacego miesiaca" << std::endl;
    std::cout << "4. Bilans z poprzedniego miesiaca" << std::endl;
    std::cout << "5. Bilans z wybranego okresu" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "6. Zmien haslo" << std::endl;
    std::cout << "7. Wyloguj sie" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Twoj wybor: ";
    choice = SupportiveMethods::readSign();
    return choice;
}

void FinanceManager::addNewIncome() {
    if (userManager.isUserLoggedIn()) {
        accountant->addNewIncome();
    } else {
        std::cout << "Aby dodac przychod, nalezy sie najpierw zalogowac" << std::endl;
        system("pause");
    }
}
void FinanceManager::addNewExpense() {
    if (userManager.isUserLoggedIn()) {
        accountant->addNewExpense();
    } else {
        std::cout << "Aby dodac wydatek, nalezy sie najpierw zalogowac" << std::endl;
        system("pause");
    }
}
void FinanceManager::displayBalanceForCurrentMonth() {
    if (userManager.isUserLoggedIn()) {
        accountant->displayBalanceForCurrentMonth();
    } else {
        std::cout << "Aby wyswietlic bilans, nalezy sie najpierw zalogowac" << std::endl;
        system("pause");
    }
}

void FinanceManager::displayBalanceForPreviousMonth() {
    if (userManager.isUserLoggedIn()) {
        accountant->displayBalanceForPreviousMonth();
    } else {
        std::cout << "Aby wyswietlic bilans, nalezy sie najpierw zalogowac" << std::endl;
        system("pause");
    }
}

void FinanceManager::displayBalanceInDateRange() {
    if (userManager.isUserLoggedIn()) {
        accountant->displayBalanceInDateRange();
    } else {
        std::cout << "Aby wyswietlic bilans, nalezy sie najpierw zalogowac" << std::endl;
        system("pause");
    }
}


