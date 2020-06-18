#ifndef _USERMODE_H
#define _USERMODE_H

#include <iostream>
#include <unistd.h>
#include <string>
#include <fstream>
#include <vector>

class UserMode {
    public: 
        void buyWithPrescription();
        void buyMedicine();
        void buyMask();
};

#endif