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

    string replaceUserDataOnDataLineSeparatedVerticalDashes(User user);
    User readUserData(string singleUserDataSeparatedbyVerticalDashes);


public:
    FileWithUsersData(string fileNameWithUsers) : FILE_WITH_USER_DATA(fileNameWithUsers) {};
    vector <User> readUsersFromFile();
    bool isFileEmpty(fstream &textFile);
    void saveUserDataInFile(User user);
    void saveAllUsersDataInFile(vector <User> &users);
};
