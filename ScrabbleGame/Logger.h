#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Logger {
private:
    std::ofstream logfile;

public:
    Logger(const std::string& fileName);
    ~Logger();
};

#endif
