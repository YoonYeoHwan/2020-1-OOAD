#ifndef _CASH_H
#define _CASH_H

#include "PaymentMethod.h"
#include <iostream>
#include <unistd.h>

class Cash: public PaymentMethod {
    public:
        void requestPayment(int);
    // private: 
    //     int price;
};

#endif