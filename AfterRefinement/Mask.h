#ifndef _MASK_H
#define _MASK_H

#include <fstream>
#include <string>

class Mask {
    public: 
        int getMask(); 
        void setMask();
    private: 
        int numOfMask;
};

#endif