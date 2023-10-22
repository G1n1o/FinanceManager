#include <iostream>
#include <vector>
#include "User.h"
#include "FileWithUsersData.h"
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

class UserManager {
    int idLoggedUser;
    vector <User> users;
    FileWithUsersData fileWithUsersData;

    User addDataNewUser();
    int getNewUserId();
    bool loginCheck(string login);
    char selectOptionFromGeneralMenu();


public:
    UserManager(string fileNameWithUsers) : fileWithUsersData(fileNameWithUsers) {
        idLoggedUser = 0;
        users = fileWithUsersData.readUsersFromFile();
    };

    void userRegistration();
    void userLogging();
    void userLogout ();
    void changePasswordLoggedUser();
    void showAllUsers();
    int getidLoggedUser();
    bool isUserLoggedIn();
};
