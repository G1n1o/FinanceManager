#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Markup.h"
#include "User.h"
#include "SupportiveMethods.h"
#include "TextFile.h"


class FileWithUsersData : public TextFile {

public:
    FileWithUsersData(std::string fileNameWithUsers) : TextFile(fileNameWithUsers) {};
    std::vector <User> readUsersFromFile();
    void saveUserDataInFile(User user);
    void saveNewPasswordInFile(std::string password, int idLoggedUser);
};
