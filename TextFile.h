#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>


class TextFile {

    const std::string FILE_NAME;

    public:
        TextFile(std::string fileName) : FILE_NAME(fileName) {
    }

    std::string getFileName();
};

#endif
