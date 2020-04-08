#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>

class Log {
    public:
        void log(int, std::string arr[] ,std::vector<std::pair<int,int>>);
        void log2(int, std::string);
};