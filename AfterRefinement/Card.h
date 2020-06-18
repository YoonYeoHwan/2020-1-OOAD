#ifndef _CARD_H
#define _CARD_H

#include "PaymentMethod.h"
#include <iostream>
#include <unistd.h>

class Card: public PaymentMethod {
    public: 
        void requestPayment(int);
    // private: 
    //     int price;
};

#endif