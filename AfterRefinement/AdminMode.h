#ifndef _ADMINMODE_H
#define _ADMINMODE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class AdminMode {
    public:
        void orderStock();
        void orderMask();
        void checkStock();
        void checkMask();
        void checkSales();
};

#endif