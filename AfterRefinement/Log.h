#ifndef _LOG_H
#define _LOG_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Log {
    public:
        void LogMedicine(int, std::string arr[], std::vector<std::pair<int, int>>);
        void LogOthers(int, std::string);
};

#endif