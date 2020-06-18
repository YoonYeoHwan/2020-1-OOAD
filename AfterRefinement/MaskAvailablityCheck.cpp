#include "MaskAvailablityCheck.h"

bool MaskAvailablityCheck::checkAvailablity(int personalID) {
    time_t timer;
    struct tm *t;
    timer = time(NULL);
    t = localtime(&timer);
    
    if(personalID / 10000 % 10 == t->tm_wday || personalID / 10000 % 10 == (t->tm_wday + 5) % 10) {
        return true;
    }
    else {
        return false;
    }
}