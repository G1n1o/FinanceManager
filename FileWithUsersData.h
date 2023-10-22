#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Markup.h"
#include "User.h"
#include "SupportiveMethods.h"


using namespace std;

class FileWithUsersData {

    const string FILE_WITH_USER_DATA;

public:
    FileWithUsersData(string fileNameWithUsers) : FILE_WITH_USER_DATA(fileNameWithUsers) {};
    vector <User> readUsersFromFile();
    void saveUserDataInFile(User user);
};
