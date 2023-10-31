#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Markup.h"
#include "User.h"
#include "SupportiveMethods.h"
#include "TextFile.h"


using namespace std;

class FileWithUsersData : public TextFile {

public:
    FileWithUsersData(string fileNameWithUsers) : TextFile(fileNameWithUsers) {};
    vector <User> readUsersFromFile();
    void saveUserDataInFile(User user);
    void saveNewPasswordInFile(string password, int idLoggedUser);
};
