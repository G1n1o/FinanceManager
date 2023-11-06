#include "UserManager.h"

void UserManager::userRegistration() {

    User user = addDataNewUser();

    users.push_back(user);
    fileWithUsersData.saveUserDataInFile(user);

    std::cout << std::endl << "Konto zalozono pomyslnie" << std::endl << std::endl;
    system("pause");

}

User UserManager::addDataNewUser() {
    User user;
    user.setIdUser(getNewUserId());

    do {
        std::cout << "Podaj login: ";
        user.setLogin(SupportiveMethods::readLine());
    } while (loginCheck(user.getLogin()) == true);

    std::cout << "Podaj haslo: ";
    user.setPassword(SupportiveMethods::readLine());
    std::cout << "Podaj Imie: ";
    user.setName(SupportiveMethods::readLine());
    user.setName(SupportiveMethods::swapFirstLetterForLargeOtherForSmall(user.getName()));
    std::cout << "Podaj Nazwisko: ";
    user.setSurname(SupportiveMethods::readLine());
    user.setSurname(SupportiveMethods::swapFirstLetterForLargeOtherForSmall(user.getSurname()));

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty())
        return 1;
    else
        return users.back().getIdUser() + 1;
}

bool UserManager::loginCheck(std::string login) {
    for (size_t i = 0 ; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            std::cout << std::endl << "Istnieje uzytkownik o takim loginie." << std::endl;
            return true;
        }
    }
    return false;
}

void UserManager::showAllUsers() {
    for (size_t i = 0 ; i < users.size(); i++) {
        std::cout << users[i].getIdUser()<<std::endl;
        std::cout << users[i].getLogin()<<std::endl;
        std::cout << users[i].getPassword()<<std::endl;
        std::cout << users[i].getName()<<std::endl;
        std::cout << users[i].getSurname()<<std::endl;
    }
    system("pause");
}

void UserManager::userLogging() {
    std::string login = "", password = "";
    std::cout << std::endl << "Podaj login: ";
    login = SupportiveMethods::readLine();
    size_t i=0;

    while (i < users.size()) {
        if (users[i].getLogin() == login) {
            for (int quantityTrials = 3; quantityTrials > 0; quantityTrials--) {
                std::cout << "Podaj haslo. Pozostalo prob: " << quantityTrials << ": ";
                password = SupportiveMethods::readLine();
                if (users[i].getPassword() == password) {
                    std::cout << std::endl << "Zalogowales sie." << std::endl << std::endl;
                    idLoggedUser = users[i].getIdUser();
                    system("pause");
                    return;
                }
            }
            std::cout << "Wprowadzono 3 razy bledne haslo." << std::endl;
            system("pause");
            return ;
        }
        i++;
    }
    std::cout << "Nie ma uzytkownika z takim loginem" << std::endl << std::endl;
    system("pause");
    return;
}

void UserManager::changePasswordLoggedUser() {
    std::string newPassword = "";
    std::cout << "Podaj nowe haslo: ";
    newPassword = SupportiveMethods::readLine();
    if (isUserLoggedIn()) {
            for (size_t i = 0; i < users.size(); i++ )
              if (users[i].getIdUser() == idLoggedUser) {
                users[i].setPassword(newPassword);
                std::cout << "Haslo zostalo zmienione." << std::endl << std::endl;
                system("pause");
                fileWithUsersData.saveNewPasswordInFile(newPassword, idLoggedUser);
            }
        } else {
        std::cout << "Aby zmienic haslo, nalezy sie najpierw zalogowac" << std::endl;
        system("pause");
    }
}

bool UserManager::isUserLoggedIn() {
    return (idLoggedUser > 0) ? true : false;
}

int UserManager::getidLoggedUser() {
    return idLoggedUser;
}

void UserManager::userLogout() {
    idLoggedUser = 0;
}


