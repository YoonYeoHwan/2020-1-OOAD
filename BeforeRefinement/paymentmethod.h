#pragma once
#include <iostream>
#include <unistd.h>

class PaymentMethod {
    public:
        void paymentCard(int);
        void paymentCash(int);
};