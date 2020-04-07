#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

class UI {
    public:
        void startProgram();
        void modeSelect(int);
        void prescription();
        void buyMedicne();
        void buyMask();
        void admin();
        void payment(int);
        void sales(int);
        void paymentCard(int);
        void paymentCash(int);
        bool receiptAsk();
        void receipt(int);
        void adminMenu();
        void adminModeSelect(int);
        void checkSales();
        void checkStock();
        void orderStock();
        void stockCount(int);
        void maskCount(int);
        void addNewProduct();
};